#include "NEW_SHELL.h"

/**
 * count_spaces - count spaces in a string
 * @new_str: string
 * Return: 0 for not a space or non-zero for space
 */
size_t count_spaces(char *new_str)
{
	int i = 0, c = 0;

	while (new_str[i])
	{
		if (isspace(new_str[i]))
		{
			c++;
		}
		i++;
	}
	return (c);
}

