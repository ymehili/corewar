/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** alive.c
*/

#include "../include/src.h"

// static void remove_champion(global_t *global, champion_t *tmp)
// {
//     champion_t *prev = global->champions;

//     if (prev == tmp) {
//         global->champions = tmp->next;
//         free(tmp);
//         return;
//     }
//     for (; prev->next != tmp; prev = prev->next);
//     prev->next = tmp->next;
//     free(tmp);
//     global->nb_champion--;
// }

// void check_alive(global_t *global)
// {
//     for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
//         if (tmp->alive == 0) {
//             printf("The champion %s is dead\n", tmp->name);
//             remove_champion(global, tmp);
//         } else {
//             tmp->alive = 0;
//         }
//     }
// }


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

void check_alive(global_t *global)
{
    champion_t *tmp = global->champions;
    champion_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        if (tmp->alive == 0) {
            if (global->nb_champion == 1) {
                printf("The champion %s is the winner!\n", tmp->name);
                return;
            }
            printf("The champion %s is dead\n", tmp->name);
            remove_champion(global, tmp);
        } else {
            tmp->alive = 0;
        }
        tmp = next;
    }
}