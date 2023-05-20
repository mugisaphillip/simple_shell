#include "shell.h"
/**
 * _puts - prints a string to screen
 * @str: string to print
 * Return: void
 */

void _puts(char *str)
{
	char c;

	while ((c = *(str++)) != '\0')
	{
		_putchar(c);
	}
}
