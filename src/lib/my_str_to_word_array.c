/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** my_str_to_word_array.c
*/

#include "../../include/lib.h"

int is_delim(char *delimiters, char c)
{
    for (int i = 0; delimiters[i] != '\0'; i++) {
        if (delimiters[i] == c)
            return 1;
    }
    return 0;
}

char *copy_until_delim(char *str, int *i, char *delimiters)
{
    int k = 0;
    char *word = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[*i] != '\0' && is_delim(delimiters, str[*i]) == 0) {
        word[k] = str[*i];
        (*i)++;
        k++;
    }
    word[k] = '\0';
    return word;
}

void make_array_null(char **array, int size)
{
    for (int i = 0; i < size; i++) {
        array[i] = NULL;
    }
}

char **my_str_to_word_array(char *str, char *delimiters)
{
    int i = 0;
    int j = 0;
    char **array = malloc(sizeof(char *) * (my_strlen(str) + 1));

    make_array_null(array, my_strlen(str) + 1);
    while (str[i] != '\0') {
        if (is_delim(delimiters, str[i]) == 0) {
            array[j] = copy_until_delim(str, &i, delimiters);
            j++;
        } else {
            i++;
        }
    }
    array[j] = NULL;
    return array;
}
