#include "shell.h"
/**
 * _getline - custom implementation of getline
 * @lineptr: pointer to buffer to write to
 * @n: size of buffer
 * Return: number of characters written
 */

ssize_t _getline(char **lineptr, size_t *n)
{
	static int BUFFER_SIZE = 1024;
	static size_t buffer_size;
	size_t n_read = 0;
	char *buffer = *lineptr;

	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
		if (buffer == NULL)
			return (-1);
		buffer_size = BUFFER_SIZE;
	}

	while (1)
	{
		n_read = read(STDIN_FILENO, buffer, buffer_size);
		if (n_read <= 0)
			return (-1);

		if (n_read == buffer_size - 1)
		{
			buffer_size *= 2;
			buffer = realloc(buffer, buffer_size);
			if (buffer == NULL)
				return (-1);
			buffer_size = n_read + 1;
		}

		buffer[n_read] = '\0';
		*n = buffer_size;
		*lineptr = buffer;
		return (n_read);
	}
}
