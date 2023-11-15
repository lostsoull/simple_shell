#include "NEW_SHELL.h"

/**
 * compare_strings - compare two strings up to a specified length
 * @str1: first string
 * @str2: second string
 * @n: the number of characters to compare
 * Return: 1 on success, 0 on failure
 */
int compare_strings(const char *str1, const char *str2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (0);
	}
	return (1);
}

/**
 * string_length - count the number of characters in a string
 * @str: input string
 * Return: number of characters
 */
size_t string_length(const char *str)
{
	size_t len = 0;

	if (!str)
		return (0);

	while (*str++)
		len++;

	return (len);
}

/**
 * copy_string - copy a string to a destination
 * @dest: destination string
 * @src: source string
 * Return: a pointer to the destination string
 */
char *copy_string(char *dest, const char *src)
{
	char *my_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (my_dest);
}

/**
 * concatenate_strings - concatenate two strings
 * @dest: destination string
 * @src: source string
 * Return: a pointer to the destination string
 */
char *concatenate_strings(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

