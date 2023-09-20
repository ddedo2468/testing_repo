#include "monty.h"

/**
 * processCommands - Process Monty bytecode commands from a file
 * @file: Pointer to the Monty bytecode file
 */
void processCommands(FILE *file)
{
char *line = NULL;
size_t len = 0;

while (1)
{
        // Allocate memory for the line buffer
        line = malloc(1024); // Adjust the buffer size as needed

        if (fgets(line, 1024, file) == NULL)
        {
            free(line); // Free the allocated memory
            if (feof(file)) // End of file reached
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
            *newline = '\0'; // Remove the newline character, if present

        char *opcode = strtok(line, " \t\n");
        char *arg = strtok(NULL, " \t\n");

        if (opcode == NULL)
            continue; // Ignore empty lines

        // Execute Monty bytecode commands
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
}

/**
 * isNumber - Check if a string is a valid integer
 * @str: String to check
 * Return: 1 if it's a valid integer, 0 otherwise
 */
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
