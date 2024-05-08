/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** st
*/

#include "../../include/src.h"

int st_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p3);

    champion->pc += 2;
    champion->reg[paramtwo & IDX_MOD] = paramone;
    champion->wait += 5;
    return 0;
}
