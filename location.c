#include "shell.h"
/**
 * location - modifies path to program
 * @path: path
 * @args: command arguments
 * Return: void
 */

void location(char **args)
{
	static int path_size = 1024;
	char pwd[1024];
	char delim[2] = "/";
	char *path = malloc(sizeof(char) * path_size);

	if (access(args[0], F_OK) == -1)
	{
		getcwd(pwd, sizeof(pwd));
		if (chdir("/bin/") == 0)
		{
			if (getcwd(path, path_size) != NULL)
			{
				strcat(path, delim);
				strcat(path, args[0]);
				path[strlen(path) + 1] = '\0';
				args[0] = path;
				if (chdir(pwd) == 0)
				{
					return;
				}
				perror("Error change directories");
			}
		}
	}
}
