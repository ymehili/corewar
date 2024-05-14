/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** xor
*/

#include "../../include/src.h"

int xor_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int paramthree = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    paramthree = get_params(global, champion, op, op->codingbyte.p2);

    champion->reg[paramthree - 1] = paramone ^ paramtwo;
    if (champion->reg[paramthree - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->wait += 6;
    champion->pc += 1;
    return 0;
}