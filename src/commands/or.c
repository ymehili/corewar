/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** or
*/

#include "../../include/src.h"

int or_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    int paramthree = get_params(global, champion, op, op->codingbyte.p2);

    champion->reg[paramthree - 1] = paramone | paramtwo;
    return 0;
}
