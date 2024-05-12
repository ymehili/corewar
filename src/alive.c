/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** alive.c
*/

#include "../include/src.h"

static void remove_champion(global_t *global, champion_t *tmp)
{
    champion_t *prev = global->champions;

    if (prev == tmp) {
        global->champions = tmp->next;
        free(tmp);
        return;
    }
    for (; prev->next != tmp; prev = prev->next);
    prev->next = tmp->next;
    free(tmp);
    global->nb_champion--;
}

void check_alive(global_t *global)
{
    for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
        if (tmp->alive == 0) {
            printf("The champion %s is dead\n", tmp->name);
            remove_champion(global, tmp);
        } else {
            tmp->alive = 0;
        }
    }
}
