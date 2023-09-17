#include "shell.h"

/**
 * get_sigint - Handles the Ctrl+C signal in the prompt.
 * @sig: The signal handler function.
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
