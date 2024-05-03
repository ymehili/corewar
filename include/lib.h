/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_
    #define NB_COMMAND 16
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <stdint.h>

char **my_str_to_word_array(char *str, char *delimiters);
int my_strcmp(const char *str1, const char *str2);
int my_getnbr(const char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
int mini_printf(const char *format, ...);

char *openfile(char *filepath);
char *getbetweenquotationmarks(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strdup(const char *str);

int swap_int_bytes(int nbr);
short swap_short_bytes(short nbr);
void *my_malloc(int size);

#endif /* !LIB_H_ */
