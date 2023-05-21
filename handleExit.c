#include "shell.h"
/**
 * handleExit - detects exit command
 * @prompt: command entered
 * @args: list of argument
 * Return void
 */

void handleExit(char *prompt, char **args)
{

	if (strcmp(prompt, "exit") != 0)
		return;

	free(args);
	free(prompt);
	_exit(0);
}
