#include "shell.h"
/**
 * location - modifies path to program
 * @args: command arguments
 * Return: void
 */

void location(char **args)
{
	char pwd[1024], path[1024];
	char delim[2] = "/";

	if (access(args[0], F_OK) == -1)
	{
		getcwd(pwd, sizeof(pwd));
		if (chdir("/bin/") == 0)
		{
			if (getcwd(path, sizeof(path)) != NULL)
			{
				strcat(path, delim);
				strcat(path, args[0]);
				args[0] = path;
				if (chdir(pwd) == 0)
					return;
				else
					perror("Error change directories");
			}
		}
	}
	return;
}
