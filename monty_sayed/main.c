#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	char *opcode;
	unsigned int line_number = 1;

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
	line = (char *)malloc(256);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, 256, file) != NULL)
	{
		opcode = strtok(line, " \t\n");
		if (opcode != NULL && strcmp(opcode, "#") != 0)
		{
			execute(opcode, &stack);
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
