/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** alive.c
*/

#include "../include/src.h"

static void remove2_champ(champion_t *prev, champion_t *tmp, global_t *global)
{
    if (prev == NULL)
        global->champions = tmp->next;
    else
        prev->next = tmp->next;
    mini_printf("The champion %d (%s) is dead\n",
        tmp->id, tmp->name);
    global->nb_champion--;
}

/**
 * @brief           Remove a champion from the list of champions.
 *
 * @param global    The global structure containing game data.
 * @param tmp       The champion to remove.
 *
 * @return          1 if the game is over, 0 otherwise.
 */
static int remove_champion(global_t *global, champion_t *tmp)
{
    champion_t *prev = NULL;

    for (champion_t *curr = global->champions; curr != NULL;
        curr = curr->next) {
        if (curr == tmp) {
            remove2_champ(prev, tmp, global);
            free(tmp);
            break;
        }
        prev = curr;
    }
    if (global->nb_champion == 1) {
        mini_printf("The champion (%s) is the winner!\n",
            global->champions->name);
        return 1;
    }
    return 0;
}

/**
 * @brief           Check if a champion is alive.
 *
 * @param global    The global structure containing game data.
 *
 * @return          0.
 */
int check_alive(global_t *global)
{
    int end = 0;
    champion_t *tmp = global->champions;
    champion_t *next;

    while (tmp != NULL) {
        next = tmp->next;
        if (tmp->alive == 0)
            end = remove_champion(global, tmp);
        else {
            tmp->alive = 0;
            mini_printf("The champion  %d (%s) is alive\n",
                tmp->id, tmp->name);
        }
        if (end == 1)
            return 0;
        tmp = next;
    }
    return 0;
}
