/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** xor
*/

#include "../../include/src.h"

int xor_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p4);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    int paramthree = get_params(global, champion, op, op->codingbyte.p2);
    int result = paramone ^ paramtwo;

    champion->reg[paramthree - 1] = result;
    if (result == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->wait += 6;
    champion->pc += 2;
    return 0;
}
