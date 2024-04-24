/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** openfile.c
*/

#include "../../include/lib.h"

char *read_file(int fd, int size)
{
    char *file = malloc(sizeof(char) * (size + 1));
    int read_size = 0;

    if (file == NULL) {
        close(fd);
        *file = -1;
        return (file);
    }
    read_size = read(fd, file, size);
    if (read_size == -1 || read_size == 0) {
        close(fd);
        return NULL;
    }
    file[read_size] = '\0';
    return file;
}

char *openfile(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = 2048;
    char *file = NULL;

    if (fd == -1){
        return NULL;
    }
    if (size == -1){
        return NULL;
    }
    file = read_file(fd, size);
    if (file == NULL || *file == -1) {
        return NULL;
    }
    close(fd);
    return file;
}
