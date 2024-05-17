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

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    if (paramone < 1 || paramone > REG_NUMBER)
        return -1;
    paramone = is_a_register(champion, paramone, op->codingbyte.p4);
    if (op->codingbyte.p3 == 0b01) {
        if (paramtwo < 1 || paramtwo > REG_NUMBER)
            return -1;
        champion->reg[paramtwo - 1] = paramone;
    } else
        global->map[(champion->pc + paramtwo % IDX_MOD) % MEM_SIZE] =
            paramone;
    champion->wait += 5;
    champion->pc += 1;
    return 0;
}
