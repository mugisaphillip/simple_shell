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
	pid_t child_pid;
	int status;

	location(args);
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("child process not created");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror(progName);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
