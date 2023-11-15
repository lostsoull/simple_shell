#include "NEW_SHELL.h"

/**
 * get_directory - check if a directory exists in the string and extracts it
 * @new_str: string
 * Return: extracted directory from the string
 */
char *get_directory(char *new_str)
{
	int i = 0, p = 0;
	char *new_str2 = "/";

	while (new_str[i])
	{
		if (new_str[i] == new_str2[p])
		{
			while (new_str[p])
			{
				new_str[p] = new_str[i];
				p++;
				i++;
			}
		}
		i++;
	}
	return (new_str);
}

