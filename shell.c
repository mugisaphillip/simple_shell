#include "shell.h"

/**
 * runInteractiveMode - runs if user is typing in commands
 * @envp: environment variables
 * @progName: program name
 * Return: void
 */
void runInteractiveMode(char *progName, char **envp)
{
	static size_t MAXWORDS = 100;
	ssize_t chars_written = 0;
	char *prompt = NULL;
	size_t len = 0;
	char **args;
	char *token = NULL;
	int n_tokens = 0;
	char delim[] = " ";

	args = malloc(sizeof(char *) * MAXWORDS);
	while (1)
	{
		_puts("#cisfun$ ");
		chars_written = getline(&prompt, &len, stdin);
		if (chars_written == -1)
			break;

		prompt[chars_written - 1] = '\0';
		token = strtok(prompt, delim);
		while (token != NULL)
		{
			args[n_tokens] = token;
			n_tokens++;
			token = strtok(NULL, delim);
		}
		args[n_tokens] = NULL;
		if (n_tokens > 0)
			execute(progName, args, envp);
		n_tokens = 0;
	}

	free(args);
	free(prompt);
}

/**
 * runNonInteractiveMode - runs if user is not typing in commands
 * @envp: environment variables
 * @progName: program name
 * Return: void
 */
void runNonInteractiveMode(char *progName, char **envp)
{
	static size_t MAXWORDS = 100;
	ssize_t chars_written = 0;
	char *prompt = NULL;
	size_t len = 0;
	char **args;
	char *token = NULL;
	int n_tokens = 0;
	char delim[] = " ";

	args = malloc(sizeof(char *) * MAXWORDS);
	chars_written = getline(&prompt, &len, stdin);
	if (chars_written == -1)
		break;

	prompt[chars_written - 1] = '\0';
	token = strtok(prompt, delim);
	while (token != NULL)
	{
		args[n_tokens] = token;
		n_tokens++;
		token = strtok(NULL, delim);
	}
	args[n_tokens] = NULL;
	if (n_tokens > 0)
		execute(progName, args, envp);
	n_tokens = 0;

	free(args);
	free(prompt);
}

/**
 * main - runs whole program
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 *
 * Return: 0 if success
 */

int main(__attribute__((unused))int ac, char **av, char **env)
{

	if (isatty(STDIN_FILENO))
		runInteractiveMode(av[0], env);
	else
		runNonInteractiveMode(av[0], env);

	return (0);
}
