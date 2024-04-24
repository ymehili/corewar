/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-myls-youssef.mehili
** File description:
** my_strdup.c
*/

#include "../../include/lib.h"

char *my_strdup(const char *str)
{
    int len;
    char *newStr;

    if (str == NULL) {
        return NULL;
    }
    len = my_strlen(str);
    newStr = malloc(sizeof(char *) * (len + 1));
    if (newStr == NULL) {
        return NULL;
    }
    my_strcpy(newStr, str);
    return newStr;
}
