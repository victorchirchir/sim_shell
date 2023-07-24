#include "main.h"
/**
 * _strcmp-compares strings
 * @str1:first string
 * @str2:second string
 * Return:int 0 if strings are same
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
/**
 * print_env-prints out current environment variables
 * Return:void
 */
void print_env(void)
{
	char **env;

	env = environ;
	while (*env != NULL)
	{
		_puts(*env);
		_puts("\n");
		env++;
	}
}

