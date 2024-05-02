/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strlen.c
*/

/**
 * @brief       Calculates the length of a string.
 *
 * @param str   The string to calculate the length of.
 * @return      The length of the string.
 */
int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
