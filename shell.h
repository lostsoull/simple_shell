#ifndef SHELL_H
#define SHELL_H
#define BUFFER_SIZE 1024
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


void _envi_vari(char **envp);
size_t space_check(char *str);
char *isdir(char *str);
int dirr(char *str);
int check_char(char *str);
char **string_split(char *str, char delim);
int _strncmp(const char *str1, const char *str2, int n);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
void shell_loop(char *envp[]);
int manage_cmd(char *buffer, char *envp[]);
char *where(char *cmd);
void split_free(char **str);

#endif
