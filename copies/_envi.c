#include "NEW_SHELL.h"

/**
 * init_environment - print environmental variables
 * @new_envp: **new_envp from the main function
 */
void init_environment(char **new_envp)
{
	int i = 0;

	while (new_envp[i] != NULL)
	{
		write(STDOUT_FILENO, new_envp[i], string_length(new_envp[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

