#include "monty.h"

void processCommands(FILE *file)
{
    char *line = NULL;
    size_t len = 0;

    while (1)
    {
        line = malloc(1024);

        if (fgets(line, 1024, file) == NULL)
        {
            free(line);
            if (feof(file))
                break;
            else
            {
                fprintf(stderr, "Error reading from file\n");
                exit(EXIT_FAILURE);
            }
        }

        line_number++;
        char *newline = strchr(line, '\n');
        if (newline)
            *newline = '\0';

        char *opcode = strtok(line, " \t\n");
        char *arg = strtok(NULL, " \t\n");

        if (opcode == NULL)
            continue;

        if (strcmp(opcode, "push") == 0)
        {
            if (arg == NULL || !isNumber(arg))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free(line);
                exit(EXIT_FAILURE);
            }
            push(atoi(arg));
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
            free(line);
            exit(EXIT_FAILURE);
        }
    }

    free(line);

    // Manually free the stack at the end
    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

