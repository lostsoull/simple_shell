#include "NEW_SHELL.h"

/**
 * print_error - to print an error and exit the program
 * @exit_code: the exit code
 * @argument: arg
 */
void print_error(int exit_code, char *argument)
{
	perror(argument);
	exit(exit_code);
}

/**
 * helper_function - make sure we have the good argv
 * @new_argv: argument vector coming from main function
 * Return: it will return the argv that we have checked
 */
char **helper_function(char **new_argv)
{
	if (!new_argv)
		print_error(1, "hsh");

	if (!is_directory(new_argv[0]))
		new_argv[0] = locate_command(new_argv[0]);

	return (new_argv);
}

/**
 * manage_command - handle user input and execute commands
 * @new_buffer: input from user
 * @new_envp: environment pointer
 * Return: 0 on success, 1 on failure, -1 to terminate terminal
 */
int manage_command(char *new_buffer, char **new_envp)
{
	pid_t pid;
	int status;
	char **new_argv;
	char *new_cmd;

	new_argv = split_input_string(new_buffer, ' ');
	new_cmd = new_argv[0];
	new_argv = helper_function(new_argv);

	if (!new_argv[0])
	{
		fprintf(stderr, "hsh: 1: %s: not found\n", new_cmd);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		execve(new_argv[0], new_argv, new_envp);
		print_error(2, new_argv[0]);
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		print_error(-1, new_argv[0]);
	}

	free_string_array(new_argv);

	return (0);
}

