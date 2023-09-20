#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack);
} instruction_t;

/*Global variables*/
extern stack_t *stack;
extern unsigned int line_number;

/*Functions prototypes*/
void push(stack_t **stack);
void pall(stack_t **stack);
void pint(stack_t **stack);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
void nop(stack_t **stack);
void execute(char *opcode, stack_t **stack);

#endif
