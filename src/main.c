/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** main
*/

#include "../include/src.h"

static void init_command(global_t *global)
{
    global->commands = malloc(sizeof(char) * NB_COMMAND + 1);
    global->commands[0] = 0x01;
    global->commands[1] = 0x02;
    global->commands[2] = 0x03;
    global->commands[3] = 0x04;
    global->commands[4] = 0x05;
    global->commands[5] = 0x06;
    global->commands[6] = 0x07;
    global->commands[7] = 0x08;
    global->commands[8] = 0x09;
    global->commands[9] = 0x0a;
    global->commands[10] = 0x0b;
    global->commands[11] = 0x0c;
    global->commands[12] = 0x0d;
    global->commands[13] = 0x0e;
    global->commands[14] = 0x0f;
    global->commands[15] = 0x10;
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
    global->live_count = 0;
    init_command(global);
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
        for (int j = 0; j < tmp->size; j++)
            global->map[debut + j] = tmp->code[j];
        tmp->alive = 1;
        tmp->pc = debut;
        tmp = tmp->next;
    }
    for (int i = 0; i < MEM_SIZE; i++)
        printf("%02hhx ", global->map[i]);
    write(1, "\n", 1);
}


static void start_game(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    static int cycle = 0;

    for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
        tmp->wait--;
        if (tmp->wait <= 0) {
            printf("for champion %s, with is pc %d is carry %d and his wait %d\n",
            tmp->name, tmp->pc, tmp->carry, tmp->wait);
            new_op(global, tmp, all_command);
        }
    }
    // printf("cycle : %d\n", cycle);
    cycle ++;
}

// void launch_game(global_t *global,
//     int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
// {
//     int check_live = 0;

//     // for(champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next)
//         // printf("champion %s and carry %d\n", tmp->name, tmp->carry);
//     while (global->nb_champion != 1) {
//         check_live++;
//         if (check_live == global->cycle_to_die && global->cycle_to_die > 0) {
//             check_live = 0;
//             printf("        check alive %d\n", global->cycle_to_die);
//             check_alive(global);
//         }
//         printf("        count_live %d and cycle to die %d\n", global->live_count ,global->cycle_to_die);
//         if (global->live_count >= NBR_LIVE) {
//             global->cycle_to_die -= CYCLE_DELTA;
//             global->live_count = 0;
//         }
//         start_game(global, all_command);
//     }
// }

void launch_game(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    int check_live = 0;

    while (global->nb_champion != 1) {
        // printf("           check live %d and cycle to die %d\n", check_live, global->cycle_to_die);
        if (check_live >= global->cycle_to_die && global->cycle_to_die > 0) {
            check_live = 0;
            // printf("        check alive %d\n", global->cycle_to_die);
            check_alive(global);
        }
        // printf("        count_live %d and cycle to die %d\n", global->live_count ,global->cycle_to_die);
        if (global->live_count >= NBR_LIVE) {
            if (global->cycle_to_die > CYCLE_DELTA) {
                global->cycle_to_die -= CYCLE_DELTA;
            } else {
                global->cycle_to_die = 1; // ou un autre seuil minimal si nécessaire
            }
            global->live_count = 0;
        }
        check_live++;
        start_game(global, all_command);
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
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *) = {
        &live_command, &ld_command, &st_command, &add_command, &sub_command,
        &and_command, &or_command, &xor_command, &zjmp_command, &ldi_command,
        &sti_command, &fork_command, &lld_command, &lldi_command,
        &lfork_command, &aff_command
    };

    if (process_args(argc, argv, global))
        return 84;
    create_map(global);
    launch_game(global, all_command);
    return 0;
}
