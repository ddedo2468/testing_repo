#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void add(stack_t **stack) 
{
    if (*stack == NULL || (*stack)->next == NULL) 
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;

    stack_t *temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL) 
    {
        (*stack)->prev = NULL;
    }
    free(temp);
}

void nop(stack_t **stack) 
{
}