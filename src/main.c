/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** main
*/

#include "../include/src.h"

/**
 * @brief   Initializes a new champion.
 *
 * @return  A pointer to the newly initialized champion.
 */
champion_t *initchampion(void)
{
    static int id = 0;
    champion_t *champion = malloc(sizeof(champion_t));

    champion->id = id;
    id++;
    champion->name = malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
    champion->comment = malloc(sizeof(char) * COMMENT_LENGTH + 1);
    champion->size = 0;
    champion->address = 0;
    champion->alive = 0;
    champion->last_live = 0;
    champion->nb_live = 0;
    champion->carry = 0;
    for (int i = 0; i < REG_NUMBER; i++)
        champion->reg[i] = 0;
    champion->instructions = NULL;
    champion->next = NULL;
    return champion;
}

void getchampioninfos(champion_t *champion, char *buffer)
{
    int i = 0;

    getheader(champion, buffer);
    return;
}

void storebuffer(char *buffer, global_t *global, champion_t *tmp)
{
    if (global->champion == NULL) {
        global->champion = malloc(sizeof(champion_t));
        tmp = global->champion;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = malloc(sizeof(champion_t));
        tmp = tmp->next;
    }
    tmp = initchampion();
    global->nb_champion++;
    getchampioninfos(tmp, buffer);
    return;
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
    ssize_t size;
    champion_t *tmp = NULL;

    for (int i = 0; i < argc; i++) {
        if (read_file(argv[i], &buffer, &size) != 0)
            return 1;
        storebuffer(buffer, global, tmp);
        free(buffer);
    }
    return 0;
}

/**
 * @brief   Initializes and returns a pointer to a global_t structure.
 *
 * @return  A pointer to the initialized global_t structure.
 */
global_t *initglobal(void)
{
    global_t *global = malloc(sizeof(global_t));

    global->champion = NULL;
    global->nb_champion = 0;
    global->cycle_to_die = CYCLE_TO_DIE;
    global->cycle = 0;
    return global;
}

/**
 * @brief The main function of the program.
 *
 * @param argc  The number of command line arguments.
 * @param argv  An array of strings containing the command line arguments.
 * @return      The exit code of the program.
 */
int main(int argc, char const *argv[])
{
    global_t *global = initglobal();

    if (process_args(argc, argv, global))
        return 84;
    return 0;
}
