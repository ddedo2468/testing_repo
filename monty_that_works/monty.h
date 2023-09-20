#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define your data structures here

extern int line_number;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

// Function prototypes for operations
int isNumber(char *str);
void push(int value);
void pall();
void pint();
void pop();
void swap();
void add();
void nop();
void freeStack();
void processCommands(FILE *file);

#endif /* MONTY_H */
