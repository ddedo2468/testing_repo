#include "monty.h"

stack_t *stack = NULL;

void push(int value)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (stack != NULL)
    {
        new_node->next = stack;
        stack->prev = new_node;
    }

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

// Function to check if a string is a valid integer
int isNumber(char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    int i = 0;
    if (str[0] == '-')
        i = 1;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }

    return 1;
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

void pop()
{
    stack_t *temp;

    if (stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
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

/**
 * freeStack - Free all elements of the stack
 */
void freeStack()
{
    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
    stack = NULL;
}
