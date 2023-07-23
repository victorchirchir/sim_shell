#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
char *_strdup(char *str);
char *_strcat(char *destn, char *src);
char *_strcpy(char *dest, char *src);
int execute(char **parsed);
char *read_line(void);
char **splits(char *line, char *delim);
int _putchar(char ch);
unsigned int _strlen(char *str);
void _puts(char *str);
char **find_path(char **environ);
char *_getenv(char **environ, char *dirname);
char *args_path(char **parse, char **tokens);
char *if_exists(char **environ);
extern char **environ;
#endif
