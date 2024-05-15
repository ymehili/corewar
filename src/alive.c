/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** alive.c
*/

#include "../include/src.h"

/**
 * @brief           Removes a champion from the list.
 *
 * @param global    The global structure containing game data.
 * @param tmp       The champion to remove.
 */
static void remove_champion(global_t *global, champion_t *tmp)
{
    champion_t *tmp_prev = NULL;

    for(champion_t *tmp2 = global->champions; tmp2->next != NULL; tmp2 = tmp2->next)
        if (tmp2->next->next == tmp->next) {
            tmp_prev = tmp2;
            break;
        }
    printf("The champion %s is dead\n", tmp->name);
    if (tmp->clone_prev != NULL)
        tmp->clone_prev->clone_next = tmp->clone_next;
    if (tmp->clone_next != NULL)
        tmp->clone_next->clone_prev = tmp->clone_prev;
    if (tmp->clone_next == NULL && tmp->clone_prev == NULL) {
        if (tmp_prev == NULL)
            global->champions = tmp->next;
        else
            tmp_prev->next = tmp->next;
        global->nb_champion--;
    }
}

/**
 * @brief           Checks if the champions are alive.
 *
 * @param global    The global structure containing game data.
 * @return          0
 */
int check_alive(global_t *global)
{
    for(champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
        if (global->nb_champion == 1) {
            printf("The champion %s is the winner!\n", tmp->name);
            return 1;
        }
        for (champion_t *tmp2 = tmp; tmp2 != NULL; tmp2 = tmp2->clone_next) {
            if (tmp2->alive == 0)
                remove_champion(global, tmp2);
            else
                tmp2->alive = 0;
        }
    }
    return 0;
}
