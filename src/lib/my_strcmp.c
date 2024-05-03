/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-youssef.mehili
** File description:
** my_strcmp.c
*/

#include "../../include/lib.h"

/**
 * @brief       Compares two strings lexicographically.
 *
 * @param str1  The first string to be compared.
 * @param str2  The second string to be compared.
 * @return      An integer greater than, equal to, or less than 0, depending on
 *              whether `str1` is greater than, equal to, or less than `str2`.
 */
int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
