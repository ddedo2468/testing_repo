#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 */
void pint()
{
    if (stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack->n);
}

/**
 * pop - Removes the top element of the stack.
 */
void pop()
{
    if (stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = stack;
    stack = stack->next;

    if (stack != NULL)
        stack->prev = NULL;

    free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 */
void swap()
{
    if (stack == NULL || stack->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    int temp = stack->n;
    stack->n = stack->next->n;
    stack->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack.
 */
void add()
{
    if (stack == NULL || stack->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack->next->n += stack->n;
    pop();
}

/**
 * nop - Does nothing.
 */
void nop()
{
    // This function does nothing.
}