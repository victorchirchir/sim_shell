#include "main.h"
/**
 * _strcpy - copies content from one string to another
 * @dest:destination string
 * @src:source string
 * Return:copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *result;

	result = dest;
	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	/*add the null terminator*/
	*dest = '\0';
	return (result);
}
/**
 * args_path - concatenate the arguments with directories
 * @parse: pointer to the command and its arguments
 * @new: pointer to the directories array
 * Return: pointer to the concatenated path or NULL
 */
char *args_path(char **parse, char **new)
{
    struct stat status;
    char *total = NULL;
    int total_length = 0;
    int i, j, k;

    for (i = 0; new[i]; i++)
    {
        total_length = _strlen(new[i]) + 1 + _strlen(parse[0]) + 1;
        for (j = 0; parse[j]; j++)
        {
            total_length += _strlen(parse[j]) + 1;
        }

        total = malloc(total_length);

        if (total == NULL)
        {
            perror("malloc");
            return NULL;
        }

        _strcpy(total, new[i]);
        _strcat(total, "/");
        _strcat(total, parse[0]);

        for (k = 1; parse[k] != NULL; k++)
        {
           _strcat(total, " ");
           _strcat(total, parse[k]);
        }

        if (stat(total, &status) == 0)
        {
            /*Perform the necessary actions with the executable path*/
            /*Free the allocated memory for total after executing the command*/
		return total;
        }

        free(total);
    }

    return NULL; /* Return NULL if no valid executable is found*/
}
