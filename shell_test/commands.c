 #include "shell.h"

/**
  * execute_command - Executes a command with the provided arguments
  * by creating a child process
  * @command: The command to be executed
  * @args: pointer to array of argument strings for the command
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
			fprintf(stderr, "Error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, NULL, 0);
	}
}
