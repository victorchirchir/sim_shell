#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes a char to stdout
 * @ch: char to be printed
 *
 * Return: On success 1 and -1 on error
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 *_puts - will print out a string
 *@str: string to be printed
 */

void _puts(char *str)
{
	int j = 0;

	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
	fflush(stdout);
}


/**
 *_strlen - determines string length
 *@str:string
 * Return: 0 on success
 */

unsigned int _strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strdup - duplicates a string
 * @str:string to be duplicated
 * Return:pointer to the duplicated new string
 */
char *_strdup(char *str)
{
	int i;
	char *new_str;

	if (str == NULL)
	{
		return (NULL);
	}
	new_str = malloc((_strlen(str) + 1) * sizeof(char));
	if (new_str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0';i++)
	{
		new_str[i] = str[i];
	}
	new_str[i] = '\0';
	return (new_str);
}

/**
 * _strcat - concatinates two strings
 * @src:pointer to the source string
 * @destn:pointer to the destination 
 * Return:pointer to the concatinated string
 */

char *_strcat(char *destn, char *src)
{
	char *dest_end;

	dest_end = destn;
	while (*dest_end)
	{
		dest_end++;
	}
	while(*src)
	{
		*dest_end = *src;
		dest_end++;
		src++;
	}
	*dest_end = '\0';
	return (destn);
}

