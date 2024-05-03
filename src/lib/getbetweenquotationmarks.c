/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** getbetweenquotationmarks
*/

#include "../../include/lib.h"

/**
 * @brief       Copies characters from the source string until a quotation mark
 *              is encountered. The copied characters are stored in the
 *              destination string.
 *
 * @param src   The source string to copy from.
 * @param start The starting index in the source string.
 * @param dest  The destination string to copy to.
 * @return      The index of the character after the quotation mark in the
 *              source string.
 */
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

/**
 * @brief       Retrieves the substring enclosed between the first pair of quotation marks
 *              in a given string.
 *
 * @param str   The input string.
 * @return      A string containing the substring between the quotation marks,
 *              or NULL if no quotation marks are found or memory allocation
 *              fails.
 */
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
