/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** add
*/

#include "../../include/src.h"

int add_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p2);
    int paramthree = get_params(global, champion, op, op->codingbyte.p3);

    champion->reg[paramthree - 1] = paramone + paramtwo;
    return 0;
}
