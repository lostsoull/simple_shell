#include "NEW_SHELL.h"

/**
 * locate_command - searches PATH directories for a command
 * @cmd: command to append to path
 * Return: path string or NULL
 */
char *locate_command(char *cmd)
{
	struct stat new_stat;
	int new_index = 0;
	char *new_all_path = getenv("PATH");
	char **new_path = NULL;
	char *new_full_path = NULL;

	if (!new_all_path)
		return (NULL);

	new_path = split_input_string(new_all_path, ':');

	while (new_path[new_index])
	{
		new_full_path = malloc(string_length(new_path[new_index]) +
				string_length(cmd) + 2);
		if (!new_full_path)
			return (NULL);

		copy_string(new_full_path, new_path[new_index]);
		concatenate_strings(new_full_path, "/");
		concatenate_strings(new_full_path, cmd);

		if (stat(new_full_path, &new_stat) == 0)
		{
			free_string_array(new_path);
			return (new_full_path);
		}

		free(new_full_path);
		new_full_path = NULL;
		new_index++;
	}
	free_string_array(new_path);
	return (NULL);
}

