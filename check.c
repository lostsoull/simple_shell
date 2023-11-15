#include "NEW_SHELL.h"

/**
 * contains_special_char - checks to see if a string contains characters
 * @new_str: string to check
 *
 * Return: number of characters. 0 if there are no characters
 */
int contains_special_char(char *new_str)
{
	int i, n = 0;

	for (i = 0; new_str[i] != '\0'; i++)
	{
		if (new_str[i] >= 'a' && new_str[i] <= 'z')
			n++;
	}
	return (n);
}

