#include "main.h"

/**
 * _strncmp-compares one string to another
 * @str1:string one
 * @str2:string two
 * @num:number of chars in prompt
 * Return: returns 0 if the strings are equal
 */
int _strncmp(const char *str1, const char *str2, int num)
{
	int i;

	for (i = 0; i < num; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		else if (str1[i] == '\0' && str2[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
void exit_func(void)
{
	exit(EXIT_SUCCESS);/*terminate program with successful exit statues*/
}
/**
 * _getenv-gets path in environ
 * @environ:global variable
 * @prompt:prompt from user
 * Return:val or null
 */
char *_getenv(char **environ, char *prompt)
{
	char *val = NULL;
	int len, i;

	len = _strlen(prompt);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], prompt, len) == 0 && environ[i][len] == '=')
		{
			val = environ[i] + len + 1;
			break;
		}
	}
	return (val);
}
