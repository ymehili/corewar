/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-myls-youssef.mehili
** File description:
** my_strdup.c
*/

#include "../../include/lib.h"

/**
 * @brief       Duplicate a string.
 *
 * @param str   The string to be duplicated.
 * @return      A pointer to the duplicated string, or NULL if `str` is NULL or
 *              if memory allocation fails.
 */
char *my_strdup(const char *str)
{
    int len;
    char *newStr;

    if (str == NULL) {
        return NULL;
    }
    len = my_strlen(str);
    newStr = malloc(sizeof(char *) * (len + 1));
    my_strcpy(newStr, str);
    return newStr;
}
