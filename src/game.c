/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** game.c
*/

#include "../include/src.h"

int print_in_hexa(global_t *global)
{
    char hex[3];

    for (int i = 0; i < MEM_SIZE; i++) {
        hex[0] = "0123456789ABCDEF"[((unsigned char)global->map[i]) / 16];
        hex[1] = "0123456789ABCDEF"[((unsigned char)global->map[i]) % 16];
        mini_printf("%c%c ", hex[0], hex[1]);
        if ((i + 1) % 32 == 0)
            write(1, "\n", 1);
    }
    write(1, "\n", 1);
    return -2;
}

static int getwait(global_t *global, champion_t *tmp)
{
    int wait = 0;

    for (int i = 0; i < NB_COMMAND - 1; i++) {
        if (global->commands[i] == global->map[tmp->pc]) {
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
    if (tmp2->wait == -1 && tmp2->to_exec == 1) {
        new_op(global, tmp2, all_command);
        tmp2->to_exec = 0;
    }
}

int start_game(global_t *global,
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
    }
    cycle_dump++;
    global->cycle++;
    return 0;
}

void change_cycle(global_t *global)
{
    if (global->cycle_to_die > CYCLE_DELTA) {
        global->cycle_to_die -= CYCLE_DELTA;
    } else {
        global->cycle_to_die = 1;
    }
    global->live_count = 0;
}

void launch_game(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    int end = 0;

    while (global->nb_champion != 1) {
        if (global->cycle_count_die >= global->cycle_to_die &&
            global->cycle_to_die > 0) {
            global->cycle_count_die = 0;
            end = check_alive(global);
        }
        if (end == 1)
            return;
        if (global->live_count >= NBR_LIVE)
            change_cycle(global);
        global->cycle_count_die++;
        if (start_game(global, all_command) == -2)
            return;
    }
}
