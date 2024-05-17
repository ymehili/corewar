/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** xor
*/

#include "../../include/src.h"
static int xor3_command(champion_t *champion, int paramthree)
{
    if (champion->reg[paramthree - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += 1;
    champion->wait += 6;
    return 0;
}

static int xor2_command(champion_t *champion, int *paramone, int *paramtwo,
    pc_t *op)
{
    if (op->codingbyte.p4 == 0b01) {
        if (*paramone < 1 || *paramone > REG_NUMBER)
            return -1;
        *paramone = champion->reg[*paramone - 1];
    }
    if (op->codingbyte.p3 == 0b01) {
        if (*paramtwo < 1 || *paramtwo > REG_NUMBER)
            return -1;
        *paramtwo = champion->reg[*paramtwo - 1];
    }
    return 0;
}

int xor_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int paramthree = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    paramthree = get_params(global, champion, op, op->codingbyte.p2);
    if (xor2_command(champion, &paramone, &paramtwo, op) == -1)
        return -1;
    paramone = is_a_indirect(global, champion, paramone, op->codingbyte.p4);
    paramtwo = is_a_indirect(global, champion, paramtwo, op->codingbyte.p3);
    if (paramthree < 1 || paramthree > REG_NUMBER)
        return -1;
    champion->reg[paramthree - 1] = paramone ^ paramtwo;
    return xor3_command(champion, paramthree);
}
