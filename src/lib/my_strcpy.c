/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-youssef.mehili
** File description:
** my_strcpy.c
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
