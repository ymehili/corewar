/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** and
*/

#include "../../include/src.h"

int and_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    int paramthree = get_params(global, champion, op, op->codingbyte.p2);

    champion->pc += 2;
    champion->reg[paramthree - 1] = paramone & paramtwo;
    champion->wait += 6;
    return 0;
}
