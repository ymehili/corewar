/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** flags.c
*/

#include "../include/src.h"

/**
 * @brief           Reads data from a file descriptor into a buffer.
 *
 * @param fd        The file descriptor to read from.
 * @param buffer    A pointer to the buffer to store the read data.
 * @param size      A pointer to the size of the buffer.
 * @return          0 if the read operation is successful, 1 otherwise.
//  */
int read_from_file(int fd, char **buffer, int *size)
{
    int bytesread = read(fd, *buffer, *size);

    if (bytesread == -1) {
        free(*buffer);
        return 1;
    }
    return 0;
}

/**
 * @brief           Process the command line arguments and store the contents
 *                  of the files in the global structure.
 *
 * @param argc      The number of command line arguments.
 * @param argv      An array of strings containing the command line arguments.
 * @param global    A pointer to the global structure.
 * @return          Returns 0 if the operation is successful, otherwise returns
 *                  1.
 */
int process_flags(int *i, int argc, char const *argv[], global_t *global)
{
    if (my_strcmp(argv[*i], "-n") == 0 && *i + 1 < argc &&
        my_str_isnum(argv[*i + 1]) == 0) {
        global->prog_number = my_getnbr(argv[*i + 1]);
        (*i)++;
        return 1;
    }
    if (my_strcmp(argv[*i], "-a") == 0 && *i + 1 < argc &&
        my_str_isnum(argv[*i + 1]) == 0) {
        global->load_address = my_getnbr(argv[*i + 1]);
        (*i)++;
        return 1;
    }
    return 0;
}

int process_file(int i, char const *argv[], global_t *global,
    champion_t *tmp)
{
    char *buffer;
    int size;

    if (read_bfile(argv[i], &buffer, &size) != 0)
        return 1;
    storebuffer(buffer, global, tmp);
    global->prog_number = -1;
    global->load_address = -1;
    return 0;
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 1;
    return 0;
}
