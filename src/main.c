/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** main
*/

#include "../include/src.h"

/**
 * @brief           Prints the memory map in hexadecimal format.
 *
 * @param global    The global structure containing game data.
 */
void print_in_hexa(global_t *global)
{
    char hex[3];

    for (int i = 0; i < MEM_SIZE; i++) {
        hex[0] = "0123456789ABCDEF"[((unsigned char)global->map[i]) / 16];
        hex[1] = "0123456789ABCDEF"[((unsigned char)global->map[i]) % 16];
        mini_printf("%c%c ", hex[0], hex[1]);
        if ((i + 1) % 64 == 0)
            write(1, "\n", 1);
    }
    write(1, "\n", 1);
}

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
    global->dump = -1;
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
    print_in_hexa(global);
}

static void start_game(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    static int cycle = 0;
    static int cycle_dump = 0;

    if (global->dump == cycle_dump) {
        cycle_dump = 0;
        print_in_hexa(global);
    }
    for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
        tmp->wait--;
        if (tmp->wait <= 0) {
            printf("for champion %s, with is pc %d is carry %d and wait %d\n",
            tmp->name, tmp->pc, tmp->carry, tmp->wait);
            new_op(global, tmp, all_command);
        }
    }
    cycle_dump++;
    cycle ++;
}

static void change_cycle(global_t *global)
{
    if (global->cycle_to_die > CYCLE_DELTA) {
        global->cycle_to_die -= CYCLE_DELTA;
    } else {
        global->cycle_to_die = 1;
    }
    global->live_count = 0;
}

/**
 * @brief           Launches the game loop.
 *
 * @param global    The global structure containing game data.
 * @param all_command   An array of function pointers to the commands.
 */
void launch_game(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    int check_live = 0;
    int end = 0;

    while (global->nb_champion != 1) {
        if (check_live >= global->cycle_to_die && global->cycle_to_die > 0) {
            check_live = 0;
            end = check_alive(global);
        }
        if (end == 1)
            return;
        if (global->live_count >= NBR_LIVE)
            change_cycle(global);
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
