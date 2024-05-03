/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** openfile
*/

#include "../include/src.h"

/**
 * @brief       Calculates the size of a file given its file descriptor.
 *
 * @param fd    The file descriptor of the file.
 * @return      The size of the file in bytes, or -1 if an error occurred.
 */
static int get_file_size(int fd)
{
    struct stat st;

    if (fstat(fd, &st) == -1)
        return -1;
    return st.st_size;
}

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
    printf("Bytes read: %d\n", bytesread);
    if (bytesread > 0) {
        printf("Buffer contents (first few bytes): ");
        for (int i = 0; i < bytesread; i++) {
            printf("%02x ", (unsigned char)(*buffer)[i]);
        }
        printf("\n");
    }
    if (bytesread == -1) {
        free(*buffer);
        return 1;
    }
    return 0;
}

// int read_from_file(int fd, char **buffer, int *size)
// {
//     int bytesread = read(fd, *buffer, *size);
//     printf("mon bytesread (%d et buf [%s])\n", bytesread, *buffer);
//     if (bytesread == -1) {
//         free(*buffer);
//         return 1;
//     }
//     return 0;
// }
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
    *size = get_file_size(fd);
    printf("my size %d\n", *size);
    if (*size == -1)
        return 1;
    *buffer = malloc(sizeof(char *) * (*size + 1));
    if (read_from_file(fd, buffer, size)) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}
