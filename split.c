#include "NEW_SHELL.h"

/**
 * free_string_array - frees memory allocated for an array of strings
 * @new_str: pointer to char * to free
 *
 * Return: void
 */
void free_string_array(char **new_str)
{
	int i = 0;

	if (new_str)
	{
		while (new_str[i])
		{
			free(new_str[i]);
			i++;
		}
		free(new_str);
	}
}

