/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-youssef.mehili
** File description:
** my_strcpy.c
*/

/**
 * @brief       Copies a string from source to destination.
 *
 * @param dest  The destination string where the copied string will be stored.
 * @param src   The source string to be copied.
 * @return      A pointer to the destination string `dest`.
 */
char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
