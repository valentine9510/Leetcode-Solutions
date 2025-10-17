/* build & run (Linux/macOS):
   cc -std=c11 -O2 -Wall -Wextra endless_cpu.c -lpthread -o endless_cpu && ./endless_cpu
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>     // usleep, read
#include <stdint.h>
#include <string.h>

/* ----------------- Public API ----------------- */

typedef void* (*task_fn)(void* arg);
typedef void  (*completion_cb)(void* result, void* user_ctx);

/* ----------------- Job + Queue ---------------- */

typedef struct Job {
    task_fn       fn;
    void*         arg;
    completion_cb cb;
    void*         cb_ctx;
    struct Job*   next;
} Job;

typedef struct {
    Job* head;
    Job* tail;
    pthread_mutex_t mtx;
    pthread_cond_t  cv;
    bool            stop;   // set true to request shutdown
} JobQueue;

static void jq_init(JobQueue* q){
    q->head = q->tail = NULL;
    q->stop = false;
    pthread_mutex_init(&q->mtx, NULL);
    pthread_cond_init(&q->cv, NULL);
}
static void jq_destroy(JobQueue* q){
    pthread_mutex_destroy(&q->mtx);
    pthread_cond_destroy(&q->cv);
}
static void jq_push(JobQueue* q, Job* j){
    j->next = NULL;
    pthread_mutex_lock(&q->mtx);
    if(q->tail) q->tail->next = j; else q->head = j;
    q->tail = j;
    pthread_cond_signal(&q->cv); // wake one worker
    pthread_mutex_unlock(&q->mtx);
}
static Job* jq_pop(JobQueue* q){
    pthread_mutex_lock(&q->mtx);
    while(!q->head && !q->stop){
        pthread_cond_wait(&q->cv, &q->mtx); // sleep until work or stop
    }
    if(!q->head && q->stop){
        pthread_mutex_unlock(&q->mtx);
        return NULL; // graceful exit condition for workers
    }
    Job* j = q->head;
    q->head = j->next;
    if(!q->head) q->tail = NULL;
    pthread_mutex_unlock(&q->mtx);
    return j;
}

/* ----------------- CPU (thread pool) ---------------- */

typedef struct {
    size_t     n_workers;
    pthread_t* threads;
    JobQueue   queue;
} CPU;

static void* worker_loop(void* arg){
    CPU* cpu = (CPU*)arg;
    for(;;){
        Job* j = jq_pop(&cpu->queue);   // blocks when no work
        if(!j) break;                   // stop requested AND queue empty
        void* res = j->fn ? j->fn(j->arg) : NULL;
        if(j->cb) j->cb(res, j->cb_ctx);
        free(j); // job shell
        // NOTE: the callback owns and frees 'res' if needed.
    }
    return NULL;
}

void cpu_init(CPU* cpu, size_t workers){
    if(workers == 0) workers = 1;
    cpu->n_workers = workers;
    cpu->threads = (pthread_t*)calloc(workers, sizeof(pthread_t));
    jq_init(&cpu->queue);
    for(size_t i=0;i<workers;++i){
        pthread_create(&cpu->threads[i], NULL, worker_loop, cpu);
    }
}

void cpu_submit(CPU* cpu, task_fn fn, void* arg, completion_cb cb, void* cb_ctx){
    Job* j = (Job*)malloc(sizeof(Job));
    if(!j){ perror("malloc"); exit(1); }
    j->fn = fn; j->arg = arg; j->cb = cb; j->cb_ctx = cb_ctx; j->next = NULL;
    jq_push(&cpu->queue, j); // returns immediately -> asynchronous
}

void cpu_shutdown(CPU* cpu){
    // request stop and wake everyone
    pthread_mutex_lock(&cpu->queue.mtx);
    cpu->queue.stop = true;
    pthread_cond_broadcast(&cpu->queue.cv);
    pthread_mutex_unlock(&cpu->queue.mtx);

    // join workers
    for(size_t i=0;i<cpu->n_workers;++i){
        pthread_join(cpu->threads[i], NULL);
    }
    free(cpu->threads); cpu->threads = NULL;
    jq_destroy(&cpu->queue);
}

/* ----------------- Demo tasks + callbacks ---------------- */

// A simple CPU task: sum 1..N (returns long* allocated on heap)
static void* task_sum_1_to_n(void* arg){
    long n = (long)(intptr_t)arg;
    long* out = (long*)malloc(sizeof(long));
    long acc = 0;
    for(long i=1;i<=n;++i) acc += i;
    usleep(50 * 1000); // simulate work
    *out = acc;
    return out;
}
static void on_sum_done(void* result, void* user_ctx){
    (void)user_ctx;
    long* p = (long*)result;
    printf("[callback] sum = %ld\n", *p);
    free(p);
}

// Another task: sleep and return a short message
typedef struct { int ms; const char* name; } SleepArgs;
static void* task_sleep_msg(void* arg){
    SleepArgs* s = (SleepArgs*)arg;
    usleep(s->ms * 1000);
    char* buf = (char*)malloc(96);
    snprintf(buf, 96, "[%s] Slept %d ms", s->name, s->ms);
    return buf;
}
static void on_msg_done(void* result, void* user_ctx){
    const char* tag = (const char*)user_ctx;
    char* msg = (char*)result;
    printf("[callback %s] %s\n", tag ? tag : "-", msg);
    free(msg);
}

/* ----------------- Endless demo (type 'q' + Enter to quit) ---------------- */

typedef struct {
    CPU* cpu;
    volatile bool keep_running;
} ProducerCtl;

static void* producer_thread(void* arg){
    ProducerCtl* ctl = (ProducerCtl*)arg;
    long n = 100000; // will vary to show different loads
    int  tick = 0;

    while(ctl->keep_running){
        // Submit a sum task
        cpu_submit(ctl->cpu, task_sum_1_to_n, (void*)(intptr_t)n, on_sum_done, NULL);

        // Submit a sleep message task
        SleepArgs* a = (SleepArgs*)malloc(sizeof(SleepArgs));
        a->ms = 80 + (tick % 4) * 40;
        a->name = "producer";
        // free 'a' inside task? No—task reads and uses it during execution.
        // We'll free the struct in the callback by attaching it as ctx if we want.
        cpu_submit(ctl->cpu, task_sleep_msg, a,
                   /*cb=*/[](void* result, void* user_ctx){
                       // We know user_ctx is a SleepArgs* we allocated
                       SleepArgs* argp = (SleepArgs*)user_ctx;
                       char* msg = (char*)result;
                       printf("[callback auto] %s\n", msg);
                       free(msg);
                       free(argp); // free the arg we allocated
                   },
                   /*cb_ctx=*/a);

        // small pacing so we don't spam too fast
        usleep(60 * 1000);
        n += 1000;
        ++tick;
    }
    return NULL;
}

int main(void){
    CPU cpu;
    cpu_init(&cpu, 8);  // 8 workers => endless machine waiting for jobs

    // Start a simple producer that keeps submitting tasks
    ProducerCtl ctl = { .cpu = &cpu, .keep_running = true };
    pthread_t prod;
    pthread_create(&prod, NULL, producer_thread, &ctl);

    // Simple console control: type 'q' + Enter to shut down
    printf("CPU running. Type 'q' + Enter to quit.\n");
    for(;;){
        int c = getchar();
        if(c == 'q' || c == 'Q'){
            break;
        }
        if(c == EOF){
            // stdin closed; also quit
            break;
        }
    }

    // Stop producer, then shutdown CPU (workers exit gracefully)
    ctl.keep_running = false;
    pthread_join(prod, NULL);

    cpu_shutdown(&cpu);
    printf("CPU stopped cleanly.\n");
    return 0;
}
