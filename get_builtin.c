#include "shell.h"

/**
 * get_builtin - Retrieves a function pointer for a builtin command based on the command name.
 * @cmd: The name of the command.
 * Return: A function pointer to the corresponding builtin command.
 */
int (*get_builtin(char *cmd))(data_shell *)
{
    builtin_t builtin[] = {
        { "env", _env },
        { "exit", exit_shell },
        { "setenv", _setenv },
        { "unsetenv", _unsetenv },
        { "cd", cd_shell },
        { "help", get_help },
        { NULL, NULL }
    };
    int index;

    for (index = 0; builtin[index].name; index++)
    {
        if (_strcmp(builtin[index].name, cmd) == 0)
            break;
    }

    return (builtin[index].f);
}

