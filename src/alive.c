/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** alive.c
*/

#include "../include/src.h"

/**
 * @brief           Remove the champion from the list.
 *
 * @param global    The global structure containing game data.
 * @param tmp       The current champion to remove.
 */
static void remove_champion(global_t *global, champion_t *tmp)
{
    champion_t *prev = NULL;
    champion_t *current = global->champions;

    while (current != NULL && current != tmp) {
        prev = current;
        current = current->next;
    }
    if (current == tmp) {
        if (prev == NULL) {
            global->champions = tmp->next;
        } else {
            prev->next = tmp->next;
        }
        free(tmp);
        global->nb_champion--;
    }
}

/**
 * @brief           Print the winner if they are only one champion
 *                  else remove the champ
 *
 * @param global    The global structure containing game data.
 * @param tmp       The current champion to check.
 * @return          0
 */
static int dead_or_alive(global_t *global, champion_t *tmp)
{
    if (global->nb_champion == 1) {
        printf("The champion %s is the winner!\n", tmp->name);
        return 1;
    }
    printf("The champion %s is dead\n", tmp->name);
    remove_champion(global, tmp);
    return 0;
}

/**
 * @brief           Checks if the champions are alive.
 *
 * @param global    The global structure containing game data.
 * @return          0
 */
int check_alive(global_t *global)
{
    champion_t *tmp = global->champions;
    champion_t *next = NULL;
    int checker = 0;

    while (tmp != NULL && checker == 0) {
        next = tmp->next;
        if (tmp->alive == 0)
            checker = dead_or_alive(global, tmp);
        else
            tmp->alive = 0;
        tmp = next;
    }
    return 0;
}
