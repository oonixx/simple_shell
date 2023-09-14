#include "shell.h"

/**
 *  * _strdup - Duplicates a string in heap memory.
 *   * @s: Type char pointer pointing to the source string.
 *    * Return: A duplicated string.
 *     */
char *_strdup(const char *s)
{
    char *new;
        size_t lin;

            lin = _strlen(s);
                new = malloc(sizeof(char) * (lin + 1));
                    if (new == NULL)
                                                return (NULL);
                            _memcpy(new, s, lin + 1);
                                 return (new);
}

/**
 *  * _strlen - Returns the lenght of a str.
 *   * @s: Type char pointer pointing to the string.
 *    * Return: Always 0.
 *     */
int _strlen(const char *s)
{
    int lin;

        for (lin = 0; s[lin] != 0; lin++)
                         {
                                         }

                return (lin);
}

/**
 *  * cmp_chars - Compare characters of strings.
 *   * @str: The input string.
 *    * @delim: The delimiter character to compare.
 *     *
 *      * Return: 1 if are equals, 0 if not.
 *       */
int cmp_chars(char str[], const char *delim)
{
    unsigned int index, ji, ki;

    for (index = 0, ki = 0; str[index]; index++)
    {
        for (ji = 0; delim[ji]; ji++)
        {
            if (str[index] == delim[ji])
            {
                ki++;
                break;
            }
        }
    }

    if (index == ki)
        return (1);
    
    return (0);
}

/**
 *  * _strtok - Splits a string by a specified delimiter.
 *   * @str: The input string.
 *    * @delim: The delimiter character.
 *     *
 *      * Return: A string representing the split parts.
 *       */
char *_strtok(char str[], const char *delim)
{
    static char *splitted, *str_end;
    char *str_start;
    unsigned int index, bool;

    if (str != NULL)
    {
        if (cmp_chars(str, delim))
            return (NULL);
        splitted = str;
        index = _strlen(str);
        str_end = &str[index];
    }
    str_start = splitted;
    if (str_start == str_end)
        return (NULL);

    for (bool = 0; *splitted; splitted++)
    {
        if (splitted != str_start)
            if (*splitted && *(splitted - 1) == '\0')
                break;

        for (index = 0; delim[index]; index++)
        {
            if (*splitted == delim[index])
            {
                *splitted = '\0';
                if (splitted == str_start)
                    str_start++;
                break;
            }
        }
        if (bool == 0 && *splitted)
            bool = 1;
    }
    if (bool == 0)
        return (NULL);
    return (str_start);
}

/**
 *  * _isdigit - Determines if a string represents a number.
 *   *
 *    * @s: The input string to be checked.
 *     * Return: 1 if the string is a number, 0 otherwise.
 *      */
int _isdigit(const char *s)
{
    unsigned int index;

    for (index = 0; s[index]; index++)
    {
        if (s[index] < 48 || s[index] > 57)
            return (0);
    }

    return (1);
}

