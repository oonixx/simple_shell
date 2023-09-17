#include "shell.h"

/**
 *  * aux_help_env - Displays help information for the "env" builtin.
 *   * Return: No return value.
 *    */
void aux_help_env(void)
{
		char *help = "env: env [option] [name=value] [command [args]]\n\t";

			write(STDOUT_FILENO, help, _strlen(help));
				help = "Print the enviroment of the shell.\n";
					write(STDOUT_FILENO, help, _strlen(help));

}
/**
 *  * aux_help_setenv - Displays help information for the "setenv" builtin.
 *   * Return: No return value.
 *    */
void aux_help_setenv(void)
{

		char *help = "setenv: setenv (const char *name, const char *value,";

			write(STDOUT_FILENO, help, _strlen(help));
				help = "int replace)\n\t";
					write(STDOUT_FILENO, help, _strlen(help));
						help = "Add a new definition to the environment\n";
							write(STDOUT_FILENO, help, _strlen(help));
}
/**
 *  * aux_help_unsetenv - Displays help information for the "unsetenv" builtin.
 *   * Return: No return value.
 *    */
void aux_help_unsetenv(void)
{
		char *help = "unsetenv: unsetenv (const char *name)\n\t";

			write(STDOUT_FILENO, help, _strlen(help));
				help = "Remove an entry completely from the environment\n";
					write(STDOUT_FILENO, help, _strlen(help));
}

/**
 *  * aux_help_general - Entry point for displaying help information for the "help" builtin.
 *   * Return: No return value.
 *    */
void aux_help_general(void)
{
		char *help = "^-^ bash, version 1.0(1)-release\n";

			write(STDOUT_FILENO, help, _strlen(help));
				help = "These commands are defined internally.Type 'help' to see the list";
					write(STDOUT_FILENO, help, _strlen(help));
						help = "Type 'help name' to find out more about the function 'name'.\n\n ";
							write(STDOUT_FILENO, help, _strlen(help));
								help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
									write(STDOUT_FILENO, help, _strlen(help));
										help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
											write(STDOUT_FILENO, help, _strlen(help));
												help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
													write(STDOUT_FILENO, help, _strlen(help));
														help = "unsetenv [variable]\n";
															write(STDOUT_FILENO, help, _strlen(help));
}
/**
 *  * aux_help_exit - Displays help information for the "exit" builtin.
 *   * Return: No return value.
 *    */
void aux_help_exit(void)
{
		char *help = "exit: exit [n]\n Exit shell.\n";

			write(STDOUT_FILENO, help, _strlen(help));
				help = "Exits the shell with a status of N. If N is ommited, the exit";
					write(STDOUT_FILENO, help, _strlen(help));
						help = "statusis that of the last command executed\n";
							write(STDOUT_FILENO, help, _strlen(help));
}