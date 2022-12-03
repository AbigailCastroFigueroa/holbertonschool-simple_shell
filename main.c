#include "shell.h"

/**
 * main - Entry point
 * @argv: array of arguments
 * @ac: amount of arguments
 * @env: environment variable.
 *
 * Return: 0 if success, -1 if fails
 */
int main(int ac, char **argv, char **env)
{
	char *user_input = NULL, *input_copy = NULL, *token;
	size_t n = 0;
	ssize_t char_read = 0;
	const char *delim = " \n";
	int i, status, total_tokens = 0;
	pid_t pid;

	while (char_read >= 0 && ac)
	{
		_puts("$ ");
		char_read = getline(&user_input, &n, stdin);
		if (char_read == -1)
			return (-1);
		input_copy = malloc(sizeof(char) * char_read);
		if (input_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		_strcpy(input_copy, user_input);
		token = strtok(user_input, input_copy);
		while (token != NULL)
		{
			total_tokens++;
			token = strtok(NULL, delim);
		}
		total_tokens++;
		argv = malloc(sizeof(char *) * total_tokens);
		token  = strtok(input_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token) + 1);
			_strcpy(argv[i], token);
			token = NULL;
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		if (_strcmp(argv[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		if ((_strcmp(argv[0], "env") == 0) || (_strcmp(argv[0], "printenv") == 0))
		{
			int i;

			for (i = 0; env[i] != NULL; i++)
				_puts(env[i]), _putchar(10);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (-1);
		}
		if (pid == 0)
		{
			execute_command(argv);
			exit(1);
		}
		else
		wait(&status);
	}
	free(argv);
	free(input_copy);
	free(user_input);
	return (0);
}

