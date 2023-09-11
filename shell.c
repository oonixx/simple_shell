#include "shell.h"

/**
 * free_data - data structure frees
 *
 * @datash: Pointer to the data structure to be initialized
 * Return: no return is expected
 */
void free_data(data_shell *datash)
{
	unsigned int index;

	for (index = 0; datash->_environ[index]; index++)
	{
		free(datash->_environ[index]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @datash:  Pointer to the data structure to be initialized
 * @av: Argument vector containing initialization data
 * Return: no return is expected
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int index;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (index = 0; environ[index]; index++)
		;

	datash->_environ = malloc(sizeof(char *) * (index + 1));

	for (index = 0; environ[index]; index++)
	{
		datash->_environ[index] = _strdup(environ[index]);
	}

	datash->_environ[index] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - the starting point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
