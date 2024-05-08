/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lfork
*/

#include "../../include/src.h"

int lfork_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    champion->wait += 1000;
    champion->pc++;
    return 0;
}
