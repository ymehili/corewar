/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** littletobigendian
*/

#include "../../include/lib.h"

/**
 * @brief       Swaps the bytes of an integer from little-endian to big-endian
 *              format.
 *
 * @param nbr   The integer to swap the bytes of.
 * @return      The integer with the bytes swapped.
 */
int swap_int_bytes(int nbr)
{
    return ((nbr << 24) & 0xff000000) |
        ((nbr << 8) & 0x00ff0000) |
        ((nbr >> 8) & 0x0000ff00) |
        ((nbr >> 24) & 0x000000ff);
}

/**
 * @brief       Swaps the bytes of a short integer from little-endian to
 *              big-endian format.
 *
 * @param nbr   The short integer to be converted.
 * @return      The converted short integer in big-endian format.
 */
short swap_short_bytes(short nbr)
{
    return ((nbr << 8) & 0xff00) | ((nbr >> 8) & 0x00ff);
}
