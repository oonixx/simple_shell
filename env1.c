#include "shell.h"

/**
 * cmp_env_name - Compares environment variable names
 * with the name passed.
 * @nenv: The name of the environment variable to compare.
 * @name: The name passed for comparison.
 *
 * Return: 0 if they are not equal, another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
    int index;

    for (index = 0; nenv[index] != '='; index++)
    {
        if (nenv[index] != name[index])
        {
            return (0);
        }
    }

    return (index + 1);
}

/**
 * _getenv - get the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 * @_environ: The environment variable.
 *
 * Return: The value of the environment variable if found.
 * otherwise returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
    char *ptr_env;
    int index, mov;

    ptr_env = NULL;
    mov = 0;
    
    for (index = 0; _environ[index]; index++)
    {
        mov = cmp_env_name(_environ[index], name);
        if (mov)
        {
            ptr_env = _environ[index];
            break;
        }
    }

    return (ptr_env + mov);
}

/**
 * _env - Prints the environment variables.
 *
 * @datash: Data structure containing relevant information.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
    int index, ji;

    for (index = 0; datash->_environ[index]; index++)
    {
        for (ji = 0; datash->_environ[index][ji]; ji++)
            ;

        write(STDOUT_FILENO, datash->_environ[index], ji);
        write(STDOUT_FILENO, "\n", 1);
    }
    datash->status = 0;

    return (1);
}

