#include "main.h"
#define DELIM ":"
char **get_path(char **environ)
{
        char *path;
        char **tokens = NULL;

        path = _getenv(environ, "PATH");
        if (!path || *path == '\0')
        {
                /*handling when path env variable not set/empty*/
                return (NULL);
        }
        tokens = splits(path, DELIM);
        return (tokens);
}

/**getprompt-gets prompt from user
 * Return: char- the prompt obtained
 */
char *getprompt(void)
{
        char *lne = NULL;
        size_t len = 0;
        ssize_t read;

        read = getline(&lne, &len, stdin);

        if (read == -1)
        {
                /*Return NULL on failure*/
                free(lne);
                return (NULL);
        }

        if (read > 0 && lne[read - 1] == '\n')
        {
                /*remove the new line character if it exists*/
                lne[read - 1] = '\0';
        }
        else if (read == 0)
        {
                /*empty line*/
                free(lne);
                return (NULL);
        }
        return (lne);
}

/**
 * _realloc - reallocate memory
 * @ptr: void variable pointer
 * @old_size: integer
 * @new_size: integer
 * Return: Null
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	char *new;
	unsigned int i;

	if (ptr == NULL)
	{
		new = malloc(new_size);
		return (new);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new = malloc(new_size);

	if (new == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
	{
		new[i] = ((char *)ptr)[i];
	}

	free(ptr);

	return (new);
}

/**
 * splits - function that create tokens
 * @line: is a char
 * @delim: is a char
 * Return: double pointer
 */

char **splits(char *line, char *delim)
{
	char **pptoken;
	int buf = 1024, i = 0;

	pptoken = malloc(sizeof(char *) * buf);
	if (!pptoken)
		exit(99);

	pptoken[i] = strtok(line, delim);
	i++;
	while (1)
	{
		pptoken[i] = strtok(NULL, delim);
		if (i >= buf)
		{
			buf += buf;
			pptoken = _realloc(pptoken, buf, buf * (sizeof(char *)));
			if (!pptoken)
				exit(98);
		}
		if (pptoken[i] == NULL)
			break;
		i++;
	}
	return (pptoken);
}
