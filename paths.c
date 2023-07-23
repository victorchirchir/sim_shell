#include "main.h"
#define PATH_DELIMITER ":"
#define INITIAL_BUF_SIZE 1024
/**
 * get_path - function that finds the path
 * @environ: global variable environment
 * Return: path in tokens or NULL on error
 */
char **get_path(char **environ)
{
	char *path_str, **path_tokens;

	path_str = _getenv(environ, "PATH");
	if (path_str == NULL)
	{
		perror("Error: PATH environment variable not found.");
		return (NULL);
	}
	path_tokens = splits(path_str, PATH_DELIMITER);
	if (path_tokens == NULL)
	{
		perror("Error: Failed to split the PATH variable.");
		return (NULL);
	}
	return (path_tokens);
}
/**
 * getprompt - gets prompt entered by user
 * Return: line
 */
char *getprompt(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t ret = 0;

	ret = getline(&line, &size, stdin);
	if (ret == -1)
	{
		free(line);
		exit(-1);
	}
	/*Remove the newline character at the end of the input line*/
	if (ret > 0 && line[ret - 1] == '\n')
	{
		line[ret - 1] = '\0';
	}
	return (line);
}
/**
 * _realloc-function that reallocates memory
 * @ptr:pointer
 * @o_size:unsigned int-old size
 * @n_size:new size
 * Return:void
 */
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	unsigned int j;
	char *char_ptr;
	char *char_new_ptr;
	void *new_ptr;

	if (n_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (n_size <= o_size)
	{
		return (ptr); /*no need to reallocate*/
	}
	if (ptr == NULL)
	{
		return (malloc(n_size));
	}
	new_ptr = malloc(n_size);
	if (new_ptr == NULL)
	{
		return (NULL); /*memory allocation failed*/
	}
	char_ptr = (char *)ptr;
	char_new_ptr = (char *)new_ptr;
	/*copy data from old block to new block*/
	for (j = 0; j < o_size; j++)
	{
		char_new_ptr[j] = char_ptr[j];
	}
	free(ptr); /*free old memory block*/
	return (new_ptr);
}

/**
 * splits - tokenizes a string
 * @lne:string to be tokenized
 * @delim:deliminitor
 * Return:tokenized strings
 */
char **splits(char *lne, char *delim)
{
	char **pptoken = NULL;
	char **new_pptoken;
	char *token;
	int buf = INITIAL_BUF_SIZE;
	int i = 0;

	pptoken = malloc(sizeof(char *) * buf);
	if (!pptoken)
		exit(99);
	token = strtok(lne, delim);
	while (token)
	{
		pptoken[i++] = token;
		if (buf <= 1)
		{
			buf += INITIAL_BUF_SIZE;
			new_pptoken = _realloc(pptoken, buf, buf * (sizeof(char *)));
			if (!new_pptoken)
			{
				free(pptoken);
				exit(98);
			}
			pptoken = new_pptoken;
		}
		token = strtok(NULL, delim);
	}
	pptoken[i] = NULL; /*End of token array*/
	return (pptoken);
}
