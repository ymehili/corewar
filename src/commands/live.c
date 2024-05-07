/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** live
*/

#include "../../include/src.h"

int live_command(global_t *global, champion_t *champion, pc_t *op)
{
    get_register(global, champion, op);
    champion->alive = 1;
    champion->last_live = global->cycle;
    return 0;
}
