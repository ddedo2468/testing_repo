#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

unsigned int line_number = 1;

int main(int argc, char *argv[])
{
        FILE *file;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
    
        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }

        file = fopen(argv[1], "r");
        if (file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }

        while ((read = getline(&line, &len, file)) != -1)
        {
                char *opcode = strtok(line, " \t\n");
                if (opcode != NULL && strcmp(opcode, "#") != 0)
                {
                        execute_instruction(opcode, &stack);
                }
                line_number++;
        }

        fclose(file);
        if (line != NULL)
        {
                free(line);
        }

        return (0);
}
