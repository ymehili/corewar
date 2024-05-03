/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** my_str_to_word_array.c
*/

#include "../../include/lib.h"

/**
 * @brief               Checks if a character is a delimiter.
 *
 * @param delimiters    The string of delimiters to check against.
 * @param c             The character to check.
 * @return              1 if the character is a delimiter, 0 otherwise.
 */
int is_delim(char *delimiters, char c)
{
    for (int i = 0; delimiters[i] != '\0'; i++) {
        if (delimiters[i] == c)
            return 1;
    }
    return 0;
}

/**
 * @brief               Copies characters from a string until a delimiter is
 *                      encountered.
 *
 * @param str           The string to copy characters from.
 * @param i             A pointer to the current index in the string.
 * @param delimiters    The delimiters to stop copying at.
 * @return              The copied characters as a dynamically allocated
 *                      string.
 */
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

/**
 * @brief       Sets all elements of a string array to NULL.
 *
 * @param array The string array to be modified.
 * @param size  The size of the array.
 */
void make_array_null(char **array, int size)
{
    for (int i = 0; i < size; i++) {
        array[i] = NULL;
    }
}

/**
 * @brief               Splits a string into an array of words based on given
 *                      delimiters.
 *
 * @param str           The string to be split.
 * @param delimiters    The delimiters used to split the string.
 * @return              A dynamically allocated array of strings containing the
 *                      words.
 */
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
