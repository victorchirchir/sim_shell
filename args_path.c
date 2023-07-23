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
	while (*src != '\0')
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
 * execute - executes the program
 * @parsed: array with pointers
 * Return: 0
 */
int execute(char **parsed)
{
        pid_t pid;
        int status;

        pid = fork();
        if (pid == -1)
        {
                perror("Fork unsuccessfull");
        }
        else if (pid == 0)
        {
                if (execve(parsed[0], parsed, NULL) == -1)
                {
                        perror(parsed[0]);
                        exit(1);
                }
        }
        else
        {
                while (waitpid(pid, &status, WNOHANG) == 0)
                {

                }
                if (WIFEXITED(status))
                {
                        return WEXITSTATUS(status);
                }
                else
                {
                        perror("Error : Child process terminated abnormally");
                        return (-1);
                }
        }
        return (0);
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
	char *total = NULL, **cat = NULL;
	int total_length = 0, i, j, k;

	for (i = 0; new[i]; i++)
	{
		total_length = _strlen(new[i]) + 1 + _strlen(parse[0]) + 1;
		for (j = 0; parse[j]; j++)
		{
			total_length += _strlen(parse[j]) + 1;
		}
		total = malloc(total_length);
		_strcat(total, new[i]);
		_strcat(total, "/");
		_strcat(total, parse[0]);
		if (stat(total, &status) == 0)
		{
			for (k = 0; parse[k] != NULL; k++)
				;
			cat = malloc(sizeof(char *) * (k + 1)); /*Allcte mem cat array*/
			if (!cat)
			{
				perror("Memory allocation error");
				free(total);
				exit(1);
			}
			cat[k] = NULL;
			cat[0] = _strdup(total); /* Duplicate the concatenated path*/
			j = 1;
			while (parse[j])
			{
				cat[j] = _strdup(parse[j]); /*Duplicate the rest of the arguments*/
				j++;
			}
			execute(cat);
			return (total);
		}
		free(total);
	}
	return (NULL);
}


