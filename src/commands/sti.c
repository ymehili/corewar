/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** sti
*/

#include "../../include/src.h"

int sti_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p2);
    int paramthree = get_params(global, champion, op, op->codingbyte.p3);

    global->map[champion->pc + (paramtwo + paramthree) % IDX_MOD] =
        champion->reg[paramone - 1];
    return 0;
}
