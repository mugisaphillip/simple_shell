#include "shell.h"

/**
 * runProgram - runs program
 * @prompt: command entered
 * @args: command argument
 * @envp: env variables
 * @chars_written: characters written
 * @progName: program name
 * Return: void
 */
void runProgram(char *prompt, char **args, char **envp, ssize_t chars_written, char *progName)
{
	char *token = NULL;
	int n_tokens = 0;
	char delim[] = " ";
	int i = 0;

	prompt[chars_written - 1] = '\0';
	handleExit(prompt, args);

	if (strcmp(prompt, "env") == 0)
	{
		while (envp[i] != NULL)
		{
			_puts(envp[i]);
			_putchar('\n');
			i++;
		}
	}

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

	args = malloc(sizeof(char *) * MAXWORDS);
	while (1)
	{
		_puts("#cisfun$ ");
		chars_written = getline(&prompt, &len, stdin);
		if (chars_written == -1)
			break;
		runProgram(prompt, args, envp, chars_written, progName);
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

	args = malloc(sizeof(char *) * MAXWORDS);
	chars_written = getline(&prompt, &len, stdin);

	runProgram(prompt, args, envp, chars_written, progName);

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
