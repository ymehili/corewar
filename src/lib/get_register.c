/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** get_register
*/

#include "../../include/src.h"

int get_register(global_t *global, champion_t *champion, int size)
{
    int value = 0;
    int i = 0;

    for (i = 0; i < size; i++) {
        value = value << 8;
        value = value | global->map[champion->pc + 2 + i];
    }
    return value;
}
