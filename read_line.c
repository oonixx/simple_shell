#include "shell.h"

/**
 * read_line - Reads the input string.
 *
 * @i_eof: The return value of the getline function.
 * Return: The input string.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
