/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** openfile
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
 * @brief           Reads the contents of a file into a buffer.
 *
 * @param filename  The name of the file to read.
 * @param buffer    A pointer to the buffer where the file contents will be
 *                  stored.
 * @param size      A pointer to an integer where the size of the file will be
 *                  stored.
 * @return          0 if the file was successfully read, 1 otherwise.
 */
int read_bfile(const char *filename, char **buffer, int *size)
{
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
        return 1;
    *size = 32000;
    if (*size == -1)
        return 1;
    *buffer = my_malloc(sizeof(char *) * (*size + 1));
    if (read_from_file(fd, buffer, size)) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

static int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 1;
    return 0;
}

/**
 * @brief           Checks if the flag -dump is present in the command line
 *                  arguments and stores the value of the flag in the global
 *                  structure.
 *
 * @param global    A pointer to the global structure.
 * @param argc      The number of command line arguments.
 * @param argv      An array of strings containing the command line arguments.
 * @param i         A pointer to the index of the command line arguments.
 */
static void check_flag(global_t *global, int argc, char const *argv[], int *i)
{
    for (int t = 1; t < argc; t++) {
        if (my_strcmp(argv[t], "-view") == 0) {
            global->flag_print = 1;
            (*i)++;
        }
        if (my_strcmp(argv[t], "-dump") == 0 && t + 1 < argc
            && my_str_isnum(argv[t + 1]) == 0) {
            global->dump = my_getnbr(argv[t + 1]);
            (*i) += 2;
            return;
        }
    }
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
int process_args(int argc, char const *argv[], global_t *global)
{
    char *buffer;
    int size;
    champion_t *tmp = NULL;
    int i = 1;

    check_flag(global, argc, argv, &i);
    for (; i < argc; i++) {
        if (read_bfile(argv[i], &buffer, &size) != 0)
            return 1;
        storebuffer(buffer, global, tmp);
        free(buffer);
    }
    return 0;
}
