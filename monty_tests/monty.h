#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>

// Define your data structures here

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;


extern stack_t *stack;

extern int line_number;

// Function prototypes for operations
void push(int value);
void pall();
void pint();
void pop();
void swap();
void add();
void nop();
void processCommands(FILE *file);

#endif /* MONTY_H */