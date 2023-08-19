 #include "shell.h"

/**
  * execute_command - Executes a command with the provided arguments
  * @command: The command to be executed
  * @args: An array of argument strings for the command
  * Return: void
  */
void execute_command(char *command, char **args)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, NULL, 0);
	}
}
