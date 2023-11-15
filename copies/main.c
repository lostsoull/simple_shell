#include "NEW_SHELL.h"

/**
 * main - Entry point to the shell
 * @new_argc: argument count in the new_argv
 * @new_argv: array of pointers to the arguments
 * @new_envp: environment pointer
 * Return: always 0 (success)
 */
int main(int new_argc, char **new_argv, char **new_envp)
{
	(void)new_argc;
	(void)new_argv;
	execute_shell_loop(new_envp);
	return (0);
}
