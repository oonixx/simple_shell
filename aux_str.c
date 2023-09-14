#include "shell.h"

/**
 *  * _strcat - concatenate two strings.
 *   * @dest: char pointer pointing to the destination of the copied string.
 *    * @src: const char pointer pointing to the source string.
 *     * Return: a pointer to the destination.
 *      */
char *_strcat(char *dest, const char *src)
{
    int index;
    int ji;

    for (index = 0; dest[index] != '\0'; index++)
        ;

    for (ji = 0; src[ji] != '\0'; ji++)
    {
        dest[index] = src[ji];
        index++;
    }

    dest[index] = '\0';
    return (dest);
}
/**
 *  * *_strcpy - Copy the string pointed to by source.
 *   * @dest: Type char pointer pointing to the destination of the copied string.
 *    * @src: Type char pointer pointing to the source string.
 *     * Return: a pointer to the destination.
 *      */
char *_strcpy(char *dest, char *src)
{
    size_t o;

    for (o = 0; src[o] != '\0'; o++)
    {
        dest[o] = src[o];
    }

    dest[o] = '\0';

    return (dest);
}
/**
 *  * _strcmp - Function that compares two strings.
 *   * @s1: The first string to be compared.
 *    * @s2: The second string to be compared.
 *     * Return: Always returns 0.
 *      */
int _strcmp(char *s1, char *s2)
{
    int index;

    for (index = 0; s1[index] == s2[index] && s1[index]; index++)
        ;

    if (s1[index] > s2[index])
        return (1);
    if (s1[index] < s2[index])
        return (-1);

    return (0);
}
/**
 *  * _strchr - locates a char in a str.
 *   * @s: The string to search in.
 *    * @c: The character to locate.
 *     * Return: the pointer to the first occurrence of the char c.
 *      */
char *_strchr(char *s, char c)
{
    unsigned int index = 0;

    for (; *(s + index) != '\0'; index++)
    {
        if (*(s + index) == c)
        {
            return (s + index);
        }
    }

    if (*(s + index) == c)
    {
        return (s + index);
    }

    return ('\0');
}
/**
 *  * _strspn - gets the length of a prefix substring.
 *   * @s: The initial segment to check.
 *    * @accept: The accepted bytes.
 *     * Return: the number of accepted bytes.
 *      */
int _strspn(char *s, char *accept)
{
    int index, ji, bool;

    for (index = 0; *(s + index) != '\0'; index++)
    {
        bool = 1;
        for (ji = 0; *(accept + ji) != '\0'; ji++)
        {
            if (*(s + index) == *(accept + ji))
            {
                bool = 0;
                break;
            }
        }
        if (bool == 1)
            break;
    }
    return (index);
}

