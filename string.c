#include "NEW_SHELL.h"

/**
 * get_string - returns array of single string and null
 * @str: string to return
 * @i: number of characters in the string
 * @start: index to start from
 * @delim: the delimiter
 *
 * Return: Array of strings if success, NULL if failure
 */
char *get_string(char *str, int i, char delim, int start)
{
	int n;
	char *word;

	while (str[start] == delim)
		start += 1;

	n = i - start;
	word = malloc(n + 1);
	if (!word)
		return (NULL);

	strncpy(word, &str[start], n);
	word[n] = '\0';

	return (word);
}

/**
 * strings - returns a terminated null array of strings
 * @str: string to split up
 * @words: pointer to strings
 * @delim: the delimiter
 *
 * Return: Array of strings or NULL;
 */
char **strings(char *str, char delim, char **words)
{
	int j = 0, i = 0;
	int start = 0;

	if (str[i] == delim)
		i++;

	while (str[i] != '\0')
	{
		if (str[i] == delim && str[i - 1] != delim)
		{
			words[j] = get_string(str, i, delim, start);
			j++;
			start = i;
		}
		i++;
	}

	if (str[i] == '\0' && str[i - 1] != delim)
	{
		words[j] = get_string(str, i, delim, start);
		words[j + 1] = NULL;
		return (words);
	}
	else
	{
		words[j] = NULL;
		return (words);
	}
}

/**
 * split_input_string - splits the string at the delimiter.
 * @str: string to split
 * @delim: delimiter to use for splitting
 *
 * Return: Array of strings on success, NULL on failure
 */
char **split_input_string(char *str, char delim)
{
	int i, word_count = 0;
	char **words;

	if (!str || !delim)
		return (NULL);

	if (contains_special_char(str) == 0)
		return (NULL);

	for (i = 0; (size_t)i < string_length(str); i++)
	{
		if (str[i] == '\n')
			str[i] = delim;
	}
	i = 0;

	if (str[i] == delim)
		i++;

	while (str[i] != '\0')
	{
		if (str[i] == delim && str[i - 1] != delim)
			word_count++;
		i++;
	}

	if (str[i] == '\0' && str[i - 1] == delim)
		words = malloc((word_count + 1) * sizeof(char *));
	else
		words = malloc((word_count + 2) * sizeof(char *));

	if (!words)
		return (NULL);

	return (strings(str, delim, words));
}

