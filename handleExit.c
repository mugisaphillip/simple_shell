#include "shell.h"
/**
 * handleExit - detects exit command
 * @prompt: command entered
 * @args: list of argument
 * Return void
 */

void handleExit(char *prompt, char **args)
{
	int status = 0;

	if (strcmp(prompt, "exit") != 0)
		return;

	if (args[1])
		status = _atoi(args[1]);
	free(prompt);
	free(args);
	exit(status);
}
