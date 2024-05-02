/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** my_memset
*/

#include "../../include/src.h"

/**
 * @brief       Fills a block of memory with a specified value.
 *
 * @param s     Pointer to the memory block to be filled.
 * @param c     Value to be set. The value is passed as an int, but the
 *              function fills the block of memory using the unsigned char
 *              conversion of this value.
 * @param n     Number of bytes to be set to the value.
 * @return      Pointer to the memory block.
 */
void *my_memset(void *s, int c, size_t n)
{
    unsigned char *p = s;

    while (n != 0) {
        *p = (unsigned char)c;
        p++;
        n--;
    }
    return s;
}
