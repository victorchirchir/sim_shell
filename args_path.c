#include "main.h"

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
        total_length = strlen(new[i]) + 1 + strlen(parse[0]) + 1;
        for (j = 0; parse[j]; j++)
        {
            total_length += strlen(parse[j]) + 1;
        }

        total = malloc(total_length);

        if (total == NULL)
        {
            perror("malloc");
            return NULL;
        }

        strcpy(total, new[i]);
        strcat(total, "/");
        strcat(total, parse[0]);

        for (k = 1; parse[k] != NULL; k++)
        {
            strcat(total, " ");
            strcat(total, parse[k]);
        }

        if (stat(total, &status) == 0)
        {
            /*Perform the necessary actions with the executable path*/
            /*Free the allocated memory for total after executing the command*/
		return total; // Or return the result here if needed
        }

        free(total);
    }

    return NULL; /* Return NULL if no valid executable is found*/
}
