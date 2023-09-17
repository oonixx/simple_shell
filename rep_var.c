#include "shell.h"

/**
 * check_env - Checks if the typed variable is an environment variable.
 *
 * @h: The head of the linked list.
 * @in: The input string.
 * @data: Data structure.
 * Return: No return value.
 */
void check_env(r_var **h, char *in, data_shell *data)
{
    int row, chr, ji, lval;
    char **_envr;

    _envr = data->_environ;
    for (row = 0; _envr[row]; row++)
    {
        for (ji = 1, chr = 0; _envr[row][chr]; chr++)
        {
            if (_envr[row][chr] == '=')
            {
                lval = _strlen(_envr[row] + chr + 1);
                add_rvar_node(h, ji, _envr[row] + chr + 1, lval);
                return;
            }

            if (in[ji] == _envr[row][chr])
                ji++;
            else
                break;
        }
    }

    for (ji = 0; in[ji]; ji++)
    {
        if (in[ji] == ' ' || in[ji] == '\t' || in[ji] == ';' || in[ji] == '\n')
            break;
    }

    add_rvar_node(h, ji, NULL, 0);
}

/**
 * check_vars - Checks if the typed variable is "$$" or "$?".
 *
 * @h: The head of the linked list.
 * @in: The input string
 * @st: The last status of the shell.
 * @data: Data structure.
 * Return: No return value.
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
    int index, lst, lpd;

    lst = _strlen(st);
    lpd = _strlen(data->pid);

    for (index = 0; in[index]; index++)
    {
        if (in[index] == '$')
        {
            if (in[index + 1] == '?')
                add_rvar_node(h, 2, st, lst), index++;
            else if (in[index + 1] == '$')
                add_rvar_node(h, 2, data->pid, lpd), index++;
            else if (in[index + 1] == '\n')
                add_rvar_node(h, 0, NULL, 0);
            else if (in[index + 1] == '\0')
                add_rvar_node(h, 0, NULL, 0);
            else if (in[index + 1] == ' ')
                add_rvar_node(h, 0, NULL, 0);
            else if (in[index + 1] == '\t')
                add_rvar_node(h, 0, NULL, 0);
            else if (in[index + 1] == ';')
                add_rvar_node(h, 0, NULL, 0);
            else
                check_env(h, in + index, data);
        }
    }

    return (index);
}

/**
 * replaced_input - Replaces string into variables.
 *
 * @head: The head of the linked list.
 * @input: The input string to be replaced.
 * @new_input: The new input string with variables replaced.
 * @nlen: The length of the new input string.
 * Return: The replaced string.
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
    r_var *indx;
    int index, ji, ki;

    indx = *head;
    for (ji = index = 0; index < nlen; index++)
    {
        if (input[ji] == '$')
        {
            if (!(indx->len_var) && !(indx->len_val))
            {
                new_input[index] = input[ji];
                ji++;
            }
            else if (indx->len_var && !(indx->len_val))
            {
                for (ki = 0; ki < indx->len_var; ki++)
                    ji++;
                index--;
            }
            else
            {
                for (ki = 0; ki < indx->len_val; ki++)
                {
                    new_input[index] = indx->val[ki];
                    index++;
                }
                ji += (indx->len_var);
                index--;
            }
            indx = indx->next;
        }
        else
        {
            new_input[index] = input[ji];
            ji++;
        }
    }

    return (new_input);
}

/**
 * rep_var - Calls functions to replace string into variables.
 *
 * @input: The input string.
 * @datash: Data structure.
 * Return: The replaced string.
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = aux_itoa(datash->status);
	head = NULL;

	olen = check_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}
