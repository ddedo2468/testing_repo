#include "shell.h"
/**
  * remove_newline - Removes a trailing newline character from a string
  * @str: The string from which to remove the newline
  * Return: void
  */
void remove_newline(char *str)
{

	size_t length = strlen(str);

	if (length > 0 && str[length - 1] == '\n')
	{
		str[length - 1] = '\0';
	}
}

/**
  * tokenize_input - Parsing input string and split it into tokens
  * @input: The input string to be tokenized
  * @tokens: An array of pointers to store the tokens
  * Return: The number of tokens
  */
int tokenize_input(char *input, char **tokens)
{
	int token_count = 0;
	char *token = strtok(input, " ");

	while (token != NULL && token_count < MAX_ARG_COUNT - 1)
	{
		tokens[token_count] = token;
		token = strtok(NULL, " ");
		token_count++;
	}
	tokens[token_count] = NULL;

	return (token_count);
}

/**
  * print_prompt - Prints the shell prompt line
  * Return: void
  */
void print_prompt(void)
{
	printf("#Shell$ ");
}

/**
  * handle_exit_command - Handles the exit command, terminating the shell
  * Return: void
  */
void handle_exit_command(void)
{
	exit(EXIT_SUCCESS);
}

/**
  * handle_env_command - Handles the environment command,
  * printing environment variables
  * Return: void
  */
void handle_env_command(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
