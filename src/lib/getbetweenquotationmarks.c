/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** getbetweenquotationmarks
*/

#include "../../include/lib.h"

int copy_until_quote(char *src, int start, char *dest)
{
    int j = 0;

    while (src[start] != '"' && src[start] != '\0') {
        dest[j] = src[start];
        j++;
        start++;
    }
    dest[j] = '\0';
    return start;
}

char *getbetweenquotationmarks(char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (new_str == NULL)
        return NULL;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"') {
            i = copy_until_quote(str, i + 1, new_str);
            return new_str;
        }
    }
    return NULL;
}
