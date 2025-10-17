#include <bits/stdc++.h>

void function_pointers(void){
    // A function type: "func taking (int, int) returning int"
    int add(int a, int b);

    // A pointer to that function type:
    int (*fp)(int, int) = &add;   // & is optional: fp = add;

    // Call through the pointer:
    int r = fp(2, 3);             // same as (*fp)(2,3)

    // Make it readable with typedef:
    typedef int (*binop_t)(int, int);
    binop_t op = add;             // op points to a function like add


}


/* Passing a pointer as an argument */
int add(int a, int b)    { return a + b; }
int mul(int a, int b)    { return a * b; }

typedef int (*binop_t)(int, int);
typedef long long (*longop_t)(long long, long long);

// "Executor" that calls whatever operation you pass
int execute(binop_t f, int x, int y) {
    return f(x, y); // indirect call through function pointer
}

int execute_long(longop_t func, long long x, long long y){
    return func(x,y);
}

int main(void) {
    printf("add: %d\n", execute(add, 2, 5));
    printf("mul: %d\n", execute(mul, 3, 4));
}

/* Arrays of function pointers (jump tables) */
#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int _div(int a, int b){ return b ? a / b : 0; }

typedef int (*binop_t)(int,int);

int array_function_pointers(void) {
    binop_t table[4] = { add, sub, mul, _div }; // opcode 0..3

    int opcode = 2; // say we decoded "MUL"
    int r = table[opcode](6, 7);
    printf("result = %d\n", r);
}


/*
5) “CPU” example: you are the CPU; instructions call the right handler
*/

#include <stdio.h>
#include <stdint.h>

typedef int32_t i32;

/* 1) Define the function type every opcode handler must implement */
typedef i32 (*op_handler_t)(i32 a, i32 b);

/* 2) Handlers (the "ALU" operations) */
static i32 op_add(i32 a, i32 b) { return a + b; }
static i32 op_sub(i32 a, i32 b) { return a - b; }
static i32 op_mul(i32 a, i32 b) { return a * b; }
static i32 op_div(i32 a, i32 b) { return (b ? a / b : 0); }
static i32 op_mod(i32 a, i32 b) { return (b ? a % b : 0); }

/* 3) Opcodes as enum for readability */
typedef enum {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD,
    OP_HALT,
} opcode_t;

/* 4) An "instruction" — two registers/values and an opcode */
typedef struct {
    opcode_t op;
    i32 a;
    i32 b;
} instr_t;

/* 5) The "CPU": executes an instruction stream using a jump-table */
i32 run_program(const instr_t *program, size_t n) {
    // Dispatch table: index must match the opcode values
    static const op_handler_t dispatch[] = {
        [OP_ADD] = op_add,
        [OP_SUB] = op_sub,
        [OP_MUL] = op_mul,
        [OP_DIV] = op_div,
        [OP_MOD] = op_mod
        // OP_HALT intentionally not mapped to an ALU handler
    };

    i32 acc = 0; // pretend this is an accumulator register

    for (size_t pc = 0; pc < n; ++pc) {
        opcode_t op = program[pc].op;

        if (op == OP_HALT) {
            // Stop execution
            break;
        }

        // Fetch operands
        i32 a = program[pc].a;
        i32 b = program[pc].b;

        // Decode & execute via function pointer
        op_handler_t f = dispatch[op];  // pick handler
        i32 r = f(a, b);                // indirect call

        // Write-back: store result in our "acc"
        acc = r;

        // Trace
        printf("pc=%zu op=%d a=%d b=%d -> acc=%d\n", pc, (int)op, a, b, acc);
    }
    return acc;
}

int main(void) {
    // Program: (((7+5)*3) % 10), then halt
    instr_t prog[] = {
        { OP_ADD, 7, 5 },
        { OP_MUL, 12, 3 },
        { OP_MOD, 36, 10 },
        { OP_HALT, 0, 0 },
    };

    i32 result = run_program(prog, sizeof(prog)/sizeof(prog[0]));
    printf("final acc = %d\n", result);
    return 0;
}
