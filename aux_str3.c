#include "shell.h"

/**
 * rev_string - Reverses a string in place.
 * @s: The input string to be reversed.
 * Return: No return value.
 */
void rev_string(char *s)
{
    int count = 0, index, ji;
    char *str, temp;

    while (count >= 0)
    {
        if (s[count] == '\0')
            break;
        count++;
    }
    str = s;

    for (index = 0; index < (count - 1); index++)
    {
        for (ji = index + 1; ji > 0; ji--)
        {
            temp = *(str + ji);
            *(str + ji) = *(str + (ji - 1));
            *(str + (ji - 1)) = temp;
        }
    }
}

