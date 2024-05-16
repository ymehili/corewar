/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** game.c
*/

#include "../include/src.h"

static void new_command(global_t *global, champion_t *tmp, champion_t *tmp2,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    if (tmp2->wait == 0) {
        new_op(global, tmp2, all_command);
        if (tmp2 != tmp)
            tmp->alive += tmp2->alive;
    }
}

static void start_game(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    static int cycle = 0;
    static int cycle_dump = 0;

    if (global->dump == cycle_dump)
        return print_in_hexa(global);
    for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
        for (champion_t *tmp2 = tmp; tmp2 != NULL; tmp2 = tmp2->clone_next) {
            tmp2->wait--;
            new_command(global, tmp, tmp2, all_command);
        }
    }
    cycle_dump++;
    cycle++;
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
