#include "shell.h"
/**
 * handleChangeDir - handles changing directory
 * @args: command argumnets
 * Return: 1 if changed else 0
 */

int handleChangeDir(char **args)
{
	int status = 0;
	char *path = args[1];
	char pwd[1024];

	if (strcmp(args[0], "cd") == 0)
	{
		getcwd(pwd, sizeof(pwd));
		if (path == NULL)
			path = getenv("HOME");
		else if (strcmp(args[1], "-") == 0)
			path = getenv("OLDPWD");

		if (access(path, F_OK) == 0)
		{
			if (access(path, R_OK) == 0)
			{
				setenv("OLDPWD", pwd, 1);
				chdir(path);
				getcwd(pwd, sizeof(pwd));
				setenv("PWD", pwd, 1);
				status = 1;
			}
		}
	}

	return (status);
}
