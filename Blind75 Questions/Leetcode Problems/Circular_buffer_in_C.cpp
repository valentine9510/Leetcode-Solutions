#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    size_t head;  // write index
    size_t tail;  // read index
    size_t count; // how much data is in the buffer
} CircularBuffer;

void cb_init(CircularBuffer* cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

bool cb_is_full(CircularBuffer* cb) {
    return cb->count == BUFFER_SIZE;
}

bool cb_is_empty(CircularBuffer* cb) {
    return cb->count == 0;
}

// Write a single byte
bool cb_write(CircularBuffer* cb, uint8_t byte) {
    if (cb_is_full(cb)) return false;

    cb->buffer[cb->head] = byte;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;
    return true;
}

// Read a single byte
bool cb_read(CircularBuffer* cb, uint8_t* byte_out) {
    if (cb_is_empty(cb)) return false;

    *byte_out = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;
    return true;
}

// Write a block of memory into the circular buffer
size_t cb_write_block(CircularBuffer* cb, const uint8_t* data, size_t len) {
    size_t written = 0;

    while (written < len && cb->count < BUFFER_SIZE) {
        cb->buffer[cb->head] = data[written];
        cb->head = (cb->head + 1) % BUFFER_SIZE;
        cb->count++;
        written++;
    }

    return written; // number of bytes successfully written
}

// Read a block of memory from the circular buffer
size_t cb_read_block(CircularBuffer* cb, uint8_t* out, size_t len) {
    size_t read = 0;

    while (read < len && cb->count > 0) {
        out[read] = cb->buffer[cb->tail];
        cb->tail = (cb->tail + 1) % BUFFER_SIZE;
        cb->count--;
        read++;
    }

    return read; // number of bytes successfully read
}

/* Personal implementation */


typedef struct 
{
    /* data */
    uint8_t count;
    uint8_t head;
    uint8_t tail;
    uint8_t buffer[BUFFER_SIZE];
} Circular_buffer_in_C;

void init_buffer(Circular_buffer_in_C* input){
    input->count = input->head = input->tail = 0;
}

bool cb_write(Circular_buffer_in_C* in_cb, uint8_t byte){
    if(in_cb->count >= BUFFER_SIZE)
        return false;

    in_cb->buffer[in_cb->head] = byte;
    in_cb->head = (in_cb->head + 1) % BUFFER_SIZE;
    in_cb->count++;

    return true;
}

bool cb_read(CircularBuffer* in_cb, uint8_t* byte_out){
    if(!in_cb->count)
        return false;
    
    *byte_out =  in_cb->buffer[in_cb->tail];
    in_cb->count--;
    in_cb->tail = (in_cb->tail + 1) % BUFFER_SIZE;
    
    return true;
}

bool cb_is_empty(CircularBuffer* cb){
    return cb->count == 0;
}

bool cb_is_full(CircularBuffer* cb){
    return cb->count == BUFFER_SIZE;
}




