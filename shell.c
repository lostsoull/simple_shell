#include "NEW_SHELL.h"

/**
 * execute_shell_loop - loop that lets the shell continue running
 * @new_envp: environment pointer
 */
void execute_shell_loop(char **new_envp)
{
	char buffer[NEW_BUFFER_SIZE];
	char *read_line;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			write(1, "$ ", string_length("$ "));

		read_line = fgets(buffer, NEW_BUFFER_SIZE, stdin);

		if (!read_line || compare_strings(buffer, "exit", 4))
		{
			if (is_interactive && read_line == NULL)
				write(1, "\n", 1);
			exit(0);
		}

		if (count_spaces(buffer) == string_length(buffer))
			continue;

		if (compare_strings(buffer, "env", 3))
		{
			init_environment(new_envp);
			continue;
		}

		if (manage_command(buffer, new_envp) == -1)
			continue;
	}
}

