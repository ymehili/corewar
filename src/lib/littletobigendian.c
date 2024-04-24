/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** littletobigendian
*/

#include "../../include/lib.h"

int swap_int_bytes(int nbr)
{
    return ((nbr << 24) & 0xff000000) |
        ((nbr << 8) & 0x00ff0000) |
        ((nbr >> 8) & 0x0000ff00) |
        ((nbr >> 24) & 0x000000ff);
}

short swap_short_bytes(short nbr)
{
    return ((nbr << 8) & 0xff00) | ((nbr >> 8) & 0x00ff);
}
