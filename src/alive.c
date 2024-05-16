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
// static int remove_champion(global_t *global, champion_t *tmp)
// {
//     champion_t *prev = NULL;

//     for (champion_t *curr = global->champions; curr != NULL; curr = curr->next) {
//         if (curr == tmp) {
//             if (prev == NULL)
//                 global->champions = tmp->next;
//             else
//                 prev->next = tmp->next;
//             mini_printf("The champion %s is dead\n", tmp->name);
//             global->nb_champion--;
//             free(tmp);
//             break;
//         }
//         prev = curr;
//     }
//     if (global->nb_champion == 1) {
//         mini_printf("The champion %s is the winner!\n", global->champions->name);
//         return 1;
//     }
//     return 0;
// }


/**
 * @brief           Checks if the champions are alive.
 *
 * @param global    The global structure containing game data.
 * @return          0
 */
// int check_alive(global_t *global)
// {
//     int end = 0; 
//     for (champion_t *tmp = global->champions; tmp ; tmp = tmp->next) {
//         if (tmp->alive == 0)
//             end = remove_champion(global, tmp);
//         else
//             tmp->alive = 0;
//         if (end == 1)
//             return 0;
//     }
//     return 0;
// }
static int remove_champion(global_t *global, champion_t *tmp) {
    champion_t *prev = NULL;

    for (champion_t *curr = global->champions; curr != NULL; curr = curr->next) {
        if (curr == tmp) {
            if (prev == NULL)
                global->champions = tmp->next;
            else
                prev->next = tmp->next;
            mini_printf("The champion %s is dead\n", tmp->name);
            global->nb_champion--;
            free(tmp);
            break;
        }
        prev = curr;
    }
    if (global->nb_champion == 1) {
        mini_printf("The champion %s is the winner!\n", global->champions->name);
        return 1;
    }
    return 0;
}


int check_alive(global_t *global) {
    int end = 0;
    champion_t *tmp = global->champions;
    champion_t *next;

    while (tmp != NULL) {
        next = tmp->next; // Store the next node before potentially removing the current one
        if (tmp->alive == 0) {
            end = remove_champion(global, tmp);
        } else {
            tmp->alive = 0;
        }
        if (end == 1) {
            return 0;
        }
        tmp = next; // Move to the next node
    }
    return 0;
}

