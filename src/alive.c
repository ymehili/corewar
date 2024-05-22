/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** alive.c
*/

#include "../include/src.h"

static void remove_from_clone_list(champion_t *tmp, global_t *global)
{
    if (tmp->clone_prev != NULL) {
        if (tmp->clone_next == NULL) {
            tmp->clone_prev->clone_next = NULL;
        } else {
            tmp->clone_prev->clone_next = tmp->clone_next;
            tmp->clone_next->clone_prev = tmp->clone_prev;
        }
    } else {
        if (tmp->clone_next != NULL) {
            tmp->clone_next->clone_prev = NULL;
        }
    }
}

static void remove_from_main_list_2(champion_t *tmp, global_t *global)
{
    champion_t *prev = NULL;

    mini_printf("The champion %d (%s) is dead\n", tmp->id + 1, tmp->name);
    global->nb_champion--;
    if (global->champions == tmp) {
        global->champions = tmp->next;
        return;
    }
    for (prev = global->champions; prev != NULL &&
        prev->next != tmp; prev = prev->next);
    if (prev != NULL) {
        prev->next = tmp->next;
    }
    free(tmp);
}

static void remove_from_main_list(champion_t *tmp, global_t *global)
{
    champion_t *prev = NULL;
    champion_t *clone = NULL;

    if (tmp->clone_next == NULL) {
        remove_from_main_list_2(tmp, global);
        return;
    }
    clone = tmp->clone_next;
    clone->next = tmp->next;
    if (global->champions == tmp)
        global->champions = clone;
    else {
        for (prev = global->champions; prev != NULL &&
            prev->next != tmp; prev = prev->next);
        if (prev != NULL)
            prev->next = clone;
    }
    clone->clone_prev = NULL;
}

static int remove_champion(champion_t *tmp, champion_t *tmp2, global_t *global)
{
    if (tmp == tmp2) {
        remove_from_main_list(tmp, global);
    } else {
        remove_from_clone_list(tmp2, global);
    }
    if (global->nb_champion == 1) {
        mini_printf("The champion (%d) (%s) is the winner!\n",
            global->champions->id + 1, global->champions->name);
        return 1;
    }
    return 0;
}

static int check_alive2(champion_t *tmp, global_t *global)
{
    int end = 0;
    champion_t *next_clone;
    int pos = 0;

    for (champion_t *tmp2 = tmp; tmp2 != NULL; tmp2 = next_clone) {
        next_clone = tmp2->clone_next;
        if (tmp2->alive == 0) {
            end = remove_champion(tmp, tmp2, global);
        } else {
            tmp2->alive = 0;
            tmp2->nb_live = 0;
        }
        if (end == 1) {
            return 1;
        }
        pos++;
    }
    return 0;
}

int check_alive(global_t *global)
{
    for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
        if (check_alive2(tmp, global) == 1)
            return 1;
    }
    return 0;
}
