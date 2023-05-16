#include "shell.h"

/**
 * runInteractiveMode - runs if user is typing in commands
 * Return: void
 */
void runInteractiveMode(void)
{

}

/**
 * runNonInteractiveMode - runs if user is not typing in commands
 * Return: void
 */
void runNonInteractiveMode(void)
{

}

/**
 * main - runs whole program
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 *
 * Return: 0 if success
 */

int main(__attribute__((unused))int ac, __attribute__((unused))char **av, __attribute__((unused))char **env)
{

	if (isatty() = STDIN_FILENO)
		runInteractiveMode();
	else
		runNonInteractiveMode();

	return (0);
}
