#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

stack_t *stack = NULL; 

void push(stack_t **stack, unsigned int *line_number)
{
	int value;
	stack_t *new_node;
	char *value_str;

	value_str = strtok(NULL, " \t\n");
	if (value_str == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", *line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);	
	new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) 
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL) 
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

void pall(stack_t **stack) 
{
    stack_t *current = *stack;

    while (current != NULL) 
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint(stack_t **stack, unsigned int *line_number) 
{
    if (*stack == NULL) 
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", *line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int *line_number) 
{
	stack_t *temp;
    if (*stack == NULL) 
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", *line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL) 
    {
        (*stack)->prev = NULL;
    }
    free(temp);
}

void swap(stack_t **stack, unsigned int *line_number) 
{
	int temp;
    if (*stack == NULL || (*stack)->next == NULL) 
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", *line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
