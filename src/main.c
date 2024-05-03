/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** main
*/

#include "../include/src.h"

static void init_command(champion_t *tmp)
{
    tmp->commands = malloc(sizeof(char *) * NB_COMMAND + 1);

    tmp->commands[0] = my_strdup("0x01");
    tmp->commands[1] = my_strdup("0x02");
    tmp->commands[2] = my_strdup("0x03");
    tmp->commands[3] = my_strdup("0x04");
    tmp->commands[4] = my_strdup("0x05");
    tmp->commands[5] = my_strdup("0x06");
    tmp->commands[6] = my_strdup("0x07");
    tmp->commands[7] = my_strdup("0x08");
    tmp->commands[8] = my_strdup("0x09");
    tmp->commands[9] = my_strdup("0x0a");
    tmp->commands[10] = my_strdup("0x0b");
    tmp->commands[11] = my_strdup("0x0c");
    tmp->commands[12] = my_strdup("0x0d");
    tmp->commands[13] = my_strdup("0x0e");
    tmp->commands[14] = my_strdup("0x0f");
    tmp->commands[15] = my_strdup("0x10");
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
static int process_args(int argc, char const *argv[], global_t *global)
{
    char *buffer;
    int size;
    champion_t *tmp = NULL;

    for (int i = 1; i < argc; i++) {
        if (read_bfile(argv[i], &buffer, &size) != 0)
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
static global_t *initglobal(void)
{
    global_t *global = malloc(sizeof(global_t));

    global->champions = NULL;
    global->nb_champion = 0;
    global->cycle_to_die = CYCLE_TO_DIE;
    global->cycle = 0;
    init_command(tmp);
    return global;
}

/**
 * @brief           Creates the memory map for the Corewar game.
 *
 * @param global    The global structure containing game data.
 */
void create_map(global_t *global)
{
    int debut = 0;
    champion_t *tmp = global->champions;

    global->map = my_malloc(sizeof(char) * MEM_SIZE);
    for (int i = 0; i < global->nb_champion; i++) {
        debut = (MEM_SIZE / global->nb_champion) * i;
        printf("champion size = %s\n", tmp->name);
        for (int j = 0; j < tmp->size; j++)
            global->map[debut + j] = tmp->code[j];
        tmp->alive = 1;
        tmp->pc = debut;
        tmp = tmp->next;
    }
    for (int i = 0; i < MEM_SIZE; i++)
        printf("%02x ", global->map[i]);
}

void launch_game(global_t *global)
{
    for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
        if (tmp->wait == 0) {
            for (int i = 0; op_tab[i].mnemonique; i++)
                if (op_tab[i].code == global->map[tmp->pc]){

                }
        }
    }
}

/**
 * @brief       The main function of the program.
 *
 * @param argc  The number of command line arguments.
 * @param argv  An array of strings containing the command line arguments.
 * @return      The exit code of the program.
 */
int main(int argc, char const *argv[])
{
    global_t *global = initglobal();
    int (*all_command[NB_COMMAND])(global_t *, champion_t *) = {
        &live, &ld, &st, &add, &sub, &and, &or, &xor, &zjmp, &ldi, &sti, &fork,
        &lld, &lldi, &lfork, &aff
    };
    if (process_args(argc, argv, global))
        return 84;
    create_map(global);
    launch_game(global);
    return 0;
}
