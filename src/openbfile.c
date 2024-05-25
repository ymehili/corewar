/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** openfile
*/

#include "../include/src.h"

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
        if (my_strcmp(argv[t], "-view") == 0 && t + 1 < argc
            && my_str_isnum(argv[t + 1]) == 0) {
            global->sleep_time = my_getnbr(argv[t + 1]);
            global->flag_print = 1;
            (*i) += 2;
            t++;
            }
        if (my_strcmp(argv[t], "-dump") == 0 && t + 1 < argc
            && my_str_isnum(argv[t + 1]) == 0) {
            global->dump = my_getnbr(argv[t + 1]);
            (*i) += 2;
            t++;
        }
    }
}

static void copy_name(champion_t *tmp, champion_t *new_champion)
{
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        new_champion->name[i] = tmp->name[i];
}

static void copy_comment(champion_t *tmp, champion_t *new_champion)
{
    for (int i = 0; i < COMMENT_LENGTH; i++)
        new_champion->comment[i] = tmp->comment[i];
}

static void copy_code(champion_t *tmp, champion_t *new_champion)
{
    for (int i = 0; i < tmp->size; i++)
        new_champion->code[i] = tmp->code[i];
}

static void swap_2(champion_t *tmp, champion_t *tmp2, champion_t *tmp3)
{
    tmp->size = tmp2->size;
    tmp->code = my_malloc(sizeof(char) * (tmp2->size + 1));
    copy_code(tmp2, tmp);
    tmp->load_address = tmp2->load_address;
    tmp->reg[0] = tmp->id;
    tmp2->id = tmp3->id;
    copy_name(tmp3, tmp2);
    copy_comment(tmp3, tmp2);
    tmp2->size = tmp3->size;
    tmp2->code = my_malloc(sizeof(char) * (tmp3->size + 1));
    copy_code(tmp3, tmp2);
    tmp2->load_address = tmp3->load_address;
    tmp2->reg[0] = tmp2->id;
}

void swapchampions(champion_t *tmp, champion_t *tmp2)
{
    champion_t *tmp3 = malloc(sizeof(champion_t));

    if (tmp->id >= tmp2->id) {
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
        swap_2(tmp, tmp2, tmp3);
    }
}

void changeids(global_t *global)
{
    champion_t *tmp = global->champions;

    while (tmp != NULL && tmp->next != NULL) {
        if (tmp->id == tmp->next->id) {
            tmp->next->id += 1;
        }
        tmp = tmp->next;
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
    changeids(global);
}

int process_args(int argc, char const *argv[], global_t *global)
{
    champion_t *tmp = NULL;
    int i = 1;

    check_flag(global, argc, argv, &i);
    for (; i < argc; i++) {
        if (process_flags(&i, argc, argv, global))
            continue;
        if (process_file(i, argv, global, tmp))
            return 1;
    }
    sortchampions(global);
    for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next)
        tmp->reg[0] = tmp->id;
    return 0;
}
