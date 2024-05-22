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
            t++;
        }
    }
}


void copy_name(champion_t *tmp, champion_t *new_champion)
{
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        new_champion->name[i] = tmp->name[i];
}

void copy_comment(champion_t *tmp, champion_t *new_champion)
{
    for (int i = 0; i < COMMENT_LENGTH; i++)
        new_champion->comment[i] = tmp->comment[i];
}

void copy_code(champion_t *tmp, champion_t *new_champion)
{
    for (int i = 0; i < tmp->size; i++)
        new_champion->code[i] = tmp->code[i];
}

void swapchampions(champion_t *tmp, champion_t *tmp2) {
    champion_t *tmp3 = malloc(sizeof(champion_t));

    if (tmp->id > tmp2->id) {
        tmp3->id = tmp->id;
        tmp3->size = tmp->size;
        tmp3->load_address = tmp->load_address;
        copy_name(tmp, tmp3);
        copy_comment(tmp, tmp3);
        tmp3->code = my_malloc(sizeof(char) * (tmp->size + 1));
        copy_code(tmp, tmp3);
        tmp->id = tmp2->id;
        copy_name(tmp2, tmp);
        copy_comment(tmp2, tmp);
        tmp->size = tmp2->size;
        tmp->code = my_malloc(sizeof(char) * (tmp2->size + 1));
        copy_code(tmp2, tmp);
        tmp->load_address = tmp2->load_address;
        tmp2->id = tmp3->id;
        copy_name(tmp3, tmp2);
        copy_comment(tmp3, tmp2);
        tmp2->size = tmp3->size;
        tmp2->code = my_malloc(sizeof(char) * (tmp3->size + 1));
        copy_code(tmp3, tmp2);
        tmp2->load_address = tmp3->load_address;
    }
}

void sortchampions(global_t *global)
{
    champion_t *tmp = global->champions;
    champion_t *tmp2 = global->champions;

    for (; tmp != NULL; tmp = tmp->next) {
        for (tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next) {
            swapchampions(tmp, tmp2);
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
        if (my_strcmp(argv[i], "-n") == 0 && i + 1 < argc && my_str_isnum(argv[i + 1]) == 0) {
            global->prog_number = my_getnbr(argv[i + 1]);
            i++;
            continue;
        }
        if (my_strcmp(argv[i], "-a") == 0 && i + 1 < argc && my_str_isnum(argv[i + 1]) == 0) {
            global->load_address = my_getnbr(argv[i + 1]);
            i++;
            continue;
        }
        if (read_bfile(argv[i], &buffer, &size) != 0)
            return 1;
        storebuffer(buffer, global, tmp);
        global->prog_number = -1;
        global->load_address = -1;
    }
    sortchampions(global);
    return 0;
}
