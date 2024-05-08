/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lld
*/

#include "../../include/src.h"

int lld_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p2);

    champion->pc += 2;
    champion->reg[paramtwo - 1] = champion->pc + paramone;
    champion->wait += 5;
    return 0;
}
