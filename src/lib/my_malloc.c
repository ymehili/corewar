/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-lucas.leclerc
** File description:
** utils
*/

#include "../../include/src.h"

/**
 * @brief       Allocates memory of the specified size and initializes it with
 *              zeros.
 *
 * @param size  The size of the memory to allocate.
 * @return      A pointer to the allocated memory, or NULL if the allocation
 *              fails.
 */
void *my_malloc(int size)
{
    void *ptr = malloc(size);

    my_memset(ptr, '\0', size);
    return ptr;
}
