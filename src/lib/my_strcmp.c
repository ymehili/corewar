/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-youssef.mehili
** File description:
** my_strcmp.c
*/

#include "../../include/lib.h"

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
