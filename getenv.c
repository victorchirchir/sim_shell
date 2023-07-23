#include "main.h"

/**
 * _strcmp:compares one string to another
 * str1:string one
 * str2:string two
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
char *_getenv(char **environ, char *prompt)
{
        char *val = NULL;
        int len_prompt, i;

        len_prompt = _strlen(prompt);
        for (i = 0; environ[i] != NULL; i++)
        {
                if (_strncmp(environ[i], prompt, len_prompt) == 0 && environ[i][len_prompt] == '=')
                {
                        val = environ[i] + len_prompt + 1;
                        break;
                }
        }
        return (val);
}
