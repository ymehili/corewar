/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** game.c
*/

#include "../include/src.h"

static int getwait(global_t *global, champion_t *tmp)
{
    int wait = 0;

    // if (tmp->to_exec == 0)
    //     return 0;
    for (int i = 0; i < NB_COMMAND; i++) {
        if (global->commands[i] == tmp->code[0]) {
            wait = op_tab[i].nbr_cycles;
            break;
        }
    }
    return wait;
}

static void new_command(global_t *global, champion_t *tmp, champion_t *tmp2,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    if (tmp2->to_exec == 0) {
        tmp2->wait = getwait(global, tmp2);
        tmp2->to_exec = 1;
    }
    printf("tmp2->wait = %d\n", tmp2->wait);
    printf("tmp2->to_exec = %d\n", tmp2->to_exec);
    if (tmp2->wait == 0 && tmp2->to_exec == 1) {
        new_op(global, tmp2, all_command);
        tmp2->to_exec = 0;
        if (tmp2 != tmp)
            tmp->alive += tmp2->alive;
    }
}

static int start_game(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    static int cycle_dump = 0;

    if (global->dump == cycle_dump)
        return print_in_hexa(global);
    for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
        for (champion_t *tmp2 = tmp; tmp2 != NULL; tmp2 = tmp2->clone_next) {
            tmp2->wait--;
            new_command(global, tmp, tmp2, all_command);
        }
        if (tmp->alive == 1)
            mini_printf("The player %d (%s) his alive.\n", tmp->id, tmp->name);
    }
    cycle_dump++;
    global->cycle++;
    return 0;
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
    sfEvent event;
    
    while (sfRenderWindow_isOpen(global->window) && global->nb_champion != 1) {
        while (sfRenderWindow_pollEvent(global->window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(global->window);
        }
        display_info(global);
        if (check_live >= global->cycle_to_die && global->cycle_to_die > 0) {
            check_live = 0;
            end = check_alive(global);
        }
        if (end == 1)

            return;
        if (global->live_count >= NBR_LIVE)
            change_cycle(global);
        check_live++;
        if (start_game(global, all_command) == -2)
            return;
        // sleep(1);
    }
    sfRenderWindow_destroy(global->window);
}
