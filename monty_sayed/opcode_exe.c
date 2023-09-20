#include "monty.h"

void execute_instruction(char *opcode, stack_t **stack)
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
}
