#include "shell.h"
/**
 * handleEnvs - setting and unsetting envs
 * @args: env name and variable
 * Return: 1 if set else 0
 */

int handleEnvs(char **args)
{
	int status = 0;

	if (strcmp(args[0], "setenv") == 0)
	{
		if (args[1] == NULL || args[2] == NULL)
		{
			perror("few arguments placed");
		}
		else if (setenv(args[1], args[2], 1) != 0)
			perror("variable not set");
		status = 1;
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] == NULL)
			perror("few arguments placed");
		else if (unsetenv(args[1]) != 0)
			perror("variable not unset");
		status = 1;
	}
	return (status);
}
