/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-miniprintf-youssef.mehili
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "../../include/lib.h"

static void mini_putchar(char c, int *count)
{
    write(1, &c, 1);
    *count = *count + 1;
}

static int mini_put_nbr(int nb, int *count)
{
    if (nb < 0) {
        mini_putchar('-', count);
        nb = -nb;
    }
    if (nb == -2147483648){
        write(1, "-2147483648", 11);
        *count = *count + 1;
        return (0);
    }
    if (nb <= 9)
        mini_putchar(nb + 48, count);
    else {
        mini_put_nbr(nb / 10, count);
        mini_put_nbr(nb % 10, count);
    }
    return 0;
}

static int mini_putstr(char const *str, int *count)
{
    write(1, str, my_strlen(str));
    return 0;
}

static void function(char format, va_list *args, int *count)
{
    switch (format) {
    case 'd':
    case 'i':
        mini_put_nbr(va_arg(*args, int), count);
        break;
    case 's':
        mini_putstr(va_arg(*args, char *), count);
        break;
    case 'c':
        mini_putchar(va_arg(*args, int), count);
        break;
    case '%':
        mini_putchar('%', count);
        break;
    }
    *count = -2147483648;
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    va_start(args, format);
    while (format[i]) {
        if (format[i] == '%') {
            i++;
            function(format[i], &args, &count);
            i++;
        } else {
            mini_putchar(format[i], &count);
            i++;
        }
    }
    return count;
}
