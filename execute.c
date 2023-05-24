#include "shell.h"
/**
 * execute - run command
 * @envp: environment variables
 * @progName: program name
 * @args: command arguments
 * Return: void
 */

void execute(char *progName, char **args, char **envp)
{
	char *path = NULL;
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("child process not created");
		return;
	}

	if (child_pid == 0)
	{
		location(path, args);
		if (execve(args[0], args, envp) == -1)
		{
			free(path);
			perror(progName);
			exit(EXIT_FAILURE);
		}
		free(path);
	}
	else
		wait(&status);
}
