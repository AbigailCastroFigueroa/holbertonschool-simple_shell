#include "shell.h"

/**
 * execute_command - search for the command through the directories in the path
 * @argv: array of arguments.
 */
void execute_command(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	/* get command*/
	if (argv)
	{
	command = argv[0];
	/*execute the command with execve */
	actual_command = get_cmd_location(command);
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error: ");
		}
	}
}

/**
 * get_cmd_location - match command's directory path.
 * @command: command given.
 *
 * Return: command if succeed, NULL if fails.
 */
char *get_cmd_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_copy = _strdup(path);
		command_length = _strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}

