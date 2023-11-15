#ifndef NEW_SHELL_H
#define NEW_SHELL_H
#define NEW_BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

void init_environment(char **new_envp);
size_t count_spaces(char *str);
char *get_directory(char *str);
int is_directory(char *str);
int contains_special_char(char *str);
char **split_input_string(char *str, char delim);
int compare_strings(const char *str1, const char *str2, int n);
size_t string_length(const char *str);
char *copy_string(char *dest, const char *src);
char *concatenate_strings(char *dest, char *src);
void execute_shell_loop(char *new_envp[]);
int manage_command(char *new_buffer, char *new_envp[]);
char *locate_command(char *cmd);
void free_string_array(char **str);

#endif
