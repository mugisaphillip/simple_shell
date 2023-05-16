#include "shell.h"
/**
 * _putchar - writes a char to STDOUT
 * @c: char to be written
 * Return: void
 */

void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

