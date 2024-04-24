/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_strcat.c
*/

#include "../../include/lib.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0'){
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
