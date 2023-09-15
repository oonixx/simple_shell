#include "shell.h"

/**
 *  * _memcpy - Copies data between void pointers.
 *   * @newptr: The destination pointer.
 *    * @ptr: The source pointer.
 *     * @size: The size of the destination pointer.
 *      *
 *       * Return: No return value.
 *        */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
    char *char_ptr = (char *)ptr;
    char *char_newptr = (char *)newptr;
    unsigned int index;

    for (index = 0; index < size; index++)
        char_newptr[index] = char_ptr[index];
}

/**
 *  * _realloc - Reallocates a memory block.
 *   * @ptr: Pointer to the previously allocated memory.
 *    * @old_size: Size, in bytes, of the allocated space pointed by memory_ptr.
 *     * @new_size: New size, in bytes, of the reallocated memory block.
 *      *
 *       * Return: The memory_ptr.
 *        * If new_size equals old_size, the function returns memory_ptr without changes.
 *         * If malloc fails, it returns NULL.
 *          */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
		void *newptr;

			if (ptr == NULL)
						return (malloc(new_size));

				if (new_size == 0)
						{
									free(ptr);
											return (NULL);
												}

					if (new_size == old_size)
								return (ptr);

						newptr = malloc(new_size);
							if (newptr == NULL)
										return (NULL);

								if (new_size < old_size)
											_memcpy(newptr, ptr, new_size);
									else
												_memcpy(newptr, ptr, old_size);

										free(ptr);
											return (newptr);
}

/**
 *  * _reallocdp - Reallocates a memory block for a double pointer.
 *   * @ptr: Double pointer to the previously allocated memory.
 *    * @old_size: Size, in bytes, of the allocated space pointed by ptr.
 *     * @new_size: New size, in bytes, of the reallocated memory block.
 *      *
 *       * Return: The ptr.
 *        * If new_size equals old_size, the function returns ptr without changes.
 *         * If malloc fails, it returns NULL.
 *          */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
    char **newptr;
    unsigned int index;

    if (ptr == NULL)
        return (malloc(sizeof(char *) * new_size));

    if (new_size == old_size)
        return (ptr);

    newptr = malloc(sizeof(char *) * new_size);
    if (newptr == NULL)
        return (NULL);

    for (index = 0; index < old_size; index++)
        newptr[index] = ptr[index];

    free(ptr);

    return (newptr);
}

