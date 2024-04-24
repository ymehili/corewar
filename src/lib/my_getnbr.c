/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday10-youssef.mehili
** File description:
** my_getnbr.c
*/

#include <unistd.h>
#include <stdio.h>

int my_getnbr(const char *str)
{
    int result = 0;
    int i = 0;
    int sign = 1;

    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9')) {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (result > 2147483647 / 10 ||
        (result == 2147483647 / 10 && str[i] - '0' > 2147483647 % 10)){
            return 0;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    result = result * sign;
    return (result);
}
