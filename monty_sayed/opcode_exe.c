#include "monty.h"
/**
 * execute - Execute Monty bytecode command
 * @opcode: The Monty bytecode command to execute
 * @stack: Pointer to the top of the stack
 */
void execute(char *opcode, stack_t **stack)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction: %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
