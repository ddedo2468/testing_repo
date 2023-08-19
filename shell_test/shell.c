#include "shell.h"
/**
 * run_shell - Runs the interactive shell
 * Return: void
 */
void run_shell(void)
{
	int interactive_mode = isatty(fileno(stdin));
	char input[MAX_INPUT_LENGTH], *args[MAX_ARG_COUNT];

	while (1)
	{
		if (interactive_mode)
			print_prompt();

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (feof(stdin))
				printf("\n");
			else
			{
				perror("fgets");
				exit(EXIT_FAILURE);
			}
			break;
		}

		remove_newline(input);

		if (!strcmp(input, "exit"))
		{
			handle_exit_command();
			break;
		}
		if (!strcmp(input, "env"))
		{
			handle_env_command();
			continue;
		}

		tokenize_input(input, args);
		execute_command(args[0], args);

		if (!interactive_mode)
			print_prompt();
	}
}
/**
 * main - Entry point for the shell program
 * Return: 0
 */
int main(void)
{
	run_shell();
	return (0);
}
