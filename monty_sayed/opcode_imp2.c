#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void add(stack_t **stack) 
{
	stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL) 
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL) 
    {
        (*stack)->prev = NULL;
    }
    free(temp);
}

void nop(stack_t **stack __attribute__((unused))) 
{
}
