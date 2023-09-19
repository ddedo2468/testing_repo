#include "monty.h"
#include <stddef.h>

/**
 * push - Pushes an element onto the stack.
 * @value: The value to push onto the stack.
 */
void push(int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
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
 * pall - Prints all the values on the stack.
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
 * processCommands - Processes Monty byte code commands from a file.
 * @file: The file containing Monty byte code commands.
 */
void processCommands(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    int line_number = 0;

    while (fgets(line, len, file) != NULL)
    {
        line_number++; // Increment line number for error reporting

        // Remove trailing newline character, if present
        size_t length = strlen(line);
        if (length > 0 && line[length - 1] == '\n')
            line[length - 1] = '\0';

        // Tokenize the line to extract opcode and argument
        char *opcode = strtok(line, " ");
        char *arg = strtok(NULL, " ");

        // Ignore empty lines and lines starting with '#' (comments)
        if (opcode == NULL || opcode[0] == '#')
            continue;

        // Process Monty byte code commands based on opcode
        if (strcmp(opcode, "push") == 0)
        {
            if (arg == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }

            // Convert the argument to an integer and push it onto the stack
            int value = atoi(arg);
            push(value);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall();
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint();
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop();
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap();
        }
        else if (strcmp(opcode, "add") == 0)
        {
            add();
        }
        else if (strcmp(opcode, "nop") == 0)
        {
            nop();
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
}