#include "main.h"

/**
 * main - my main function
 * @argc:int
 * @argv: array of chars
 * @environ: global variable
 * Return: 0
 */

int main(int argc, char **argv, char **environ)
{
	char *prompt = NULL;
	char *delim = "\t \a\n";
	char *command;
	char **tokens;
	(void)argc;

	tokens = get_path(environ);

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		_puts("$ ");
		fflush(stdout);
		prompt = getprompt();
		if (_strcmp(prompt, "exit") == 0)
		{
			exit_func();
			break;
		}
		argv = splits(prompt, delim);
		command = args_path(argv, tokens);
		if (command == NULL)
			execute(argv);
		free(prompt);
		free(argv);
		free(command);
	}
	return (0);
}
