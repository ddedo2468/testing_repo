#include "monty.h"
extern int line_number;

stack_t *stack = NULL;

/**
 * push - Push an element onto the stack
 * @value: Value to push onto the stack
 */
void push(int value)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        freeStack();
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = stack;

    if (stack != NULL)
        stack->prev = new_node;

    stack = new_node;
}

/**
 * pall - Print all elements of the stack
 */
void pall()
{
    stack_t *current = stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Print the top element of the stack
 */
void pint()
{
    if (stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        freeStack();
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack->n);
}

/**
 * pop - Remove the top element of the stack
 */
void pop()
{
    stack_t *temp;

    if (stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        freeStack();
        exit(EXIT_FAILURE);
    }

    temp = stack;
    stack = stack->next;
    if (stack != NULL)
        stack->prev = NULL;

    free(temp);
}

/**
 * swap - Swap the top two elements of the stack
 */
void swap()
{
    int temp;
    
    if (stack == NULL || stack->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        freeStack();
        exit(EXIT_FAILURE);
    }

    temp = stack->n;
    stack->n = stack->next->n;
    stack->next->n = temp;
}

/**
 * add - Add the top two elements of the stack
 */
void add()
{
    if (stack == NULL || stack->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        freeStack();
        exit(EXIT_FAILURE);
    }

    stack->next->n += stack->n;
    pop();
}

/**
 * nop - Do nothing (no operation)
 */
void nop()
{
    // This function intentionally does nothing
}
void freeStack()
{
    stack_t *current = stack;
    stack_t *temp;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}
