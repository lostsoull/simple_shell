#include "NEW_SHELL.h"

/**
 * is_directory - check if the given string represents a directory
 * @new_str: string
 * Return: 1 if a directory is found in the string or 0 if not found
 */
int is_directory(char *new_str)
{
	int i = 0;

	if (new_str[0] == '/' || (new_str[0] == '.' && new_str[1] == '/'))
		i += 1;

	if (i > 0)
		return (1);

	return (0);
}

