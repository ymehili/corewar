/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** add
*/

#include "../../include/src.h"

static int add2_command(champion_t *champion, int paramthree)
{
    if (champion->reg[paramthree - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += 1;
    return 0;
}

int add_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int paramthree = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    paramthree = get_params(global, champion, op, op->codingbyte.p2);
    if (op->codingbyte.p2 != 0b01 && op->codingbyte.p3 != 0b01 &&
        op->codingbyte.p4 != 0b01)
        return -1;
    if (paramthree < 1 || paramthree > REG_NUMBER || paramone < 1 ||
        paramone > REG_NUMBER || paramtwo < 1 || paramtwo > REG_NUMBER)
        return -1;
    champion->reg[paramthree - 1] =
        champion->reg[paramone - 1] + champion->reg[paramtwo - 1];
    return add2_command(champion, paramthree);
}
