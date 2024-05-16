/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** st
*/

#include "../../include/src.h"

int st_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int val_paramone = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    val_paramone = champion->reg[paramone - 1];
    if (op->codingbyte.p3 == 0b01)
        champion->reg[paramtwo - 1] = val_paramone;
    else
        global->map[(champion->pc + paramtwo % IDX_MOD) % MEM_SIZE] =
            val_paramone;
    champion->reg[paramtwo - 1] = val_paramone;
    champion->wait += 5;
    champion->pc += 1;
    return 0;
}
