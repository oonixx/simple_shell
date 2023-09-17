#include "shell.h"

/**
 * copy_info - Copies information to create
 * a new environment or alias.
 * @name: The name (environment or alias).
 * @value: The value (environment or alias).
 *
 * Return: The new environment or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - Sets an environment variable.
 *
 * @name: The name of the environment variable.
 * @value: The value of the environment variable.
 * @datash: Data structure containing relevant information (environ).
 * Return: No return value.
 */
void set_env(char *name, char *value, data_shell *datash)
{
    int index;
    char *var_env, *name_env;

    for (index = 0; datash->_environ[index]; index++)
    {
        var_env = _strdup(datash->_environ[index]);
        name_env = _strtok(var_env, "=");
        if (_strcmp(name_env, name) == 0)
        {
            free(datash->_environ[index]);
            datash->_environ[index] = copy_info(name_env, value);
            free(var_env);
            return;
        }
        free(var_env);
    }

    datash->_environ = _reallocdp(datash->_environ, index, sizeof(char *) * (index + 2));
    datash->_environ[index] = copy_info(name, value);
    datash->_environ[index + 1] = NULL;
}

/**
 * _setenv - Compares environment variables names
 * with the name passed.
 * @datash: Data relevant (environment name and value).
 *
 * Return: 1 on success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - Deletes an environment variable.
 *
 * @datash: Data relevant (environment name).
 *
 * Return: 1 on success.
 */
int _unsetenv(data_shell *datash)
{
    char **realloc_environ;
    char *var_env, *name_env;
    int index, ji, ki;

    if (datash->args[1] == NULL)
    {
        get_error(datash, -1);
        return (1);
    }
    ki = -1;
    for (index = 0; datash->_environ[index]; index++)
    {
        var_env = _strdup(datash->_environ[index]);
        name_env = _strtok(var_env, "=");
        if (_strcmp(name_env, datash->args[1]) == 0)
        {
            ki = index;
        }
        free(var_env);
    }
    if (ki == -1)
    {
        get_error(datash, -1);
        return (1);
    }
    realloc_environ = malloc(sizeof(char *) * (index));
    for (index = ji = 0; datash->_environ[index]; index++)
    {
        if (index != ki)
        {
            realloc_environ[ji] = datash->_environ[index];
            ji++;
        }
    }
    realloc_environ[ji] = NULL;
    free(datash->_environ[ki]);
    free(datash->_environ);
    datash->_environ = realloc_environ;
    return (1);
}

