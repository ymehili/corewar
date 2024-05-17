/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** sub
*/

#include "../../include/src.h"

static int sub3_command(champion_t *champion, int paramthree)
{
    if (champion->reg[paramthree - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += 1;
    champion->wait += 10;
    return 0;
}

static int sub2_command(int *paramone, int *paramtwo,
    champion_t *champion, pc_t *op)
{
    if (op->codingbyte.p4 != 0b01 && op->codingbyte.p3 != 0b01)
        return -1;
    if (*paramone < 1 || *paramone > REG_NUMBER || *paramtwo < 1 ||
        *paramtwo > REG_NUMBER)
        return -1;
    *paramone = is_a_register(champion, *paramone, op->codingbyte.p4);
    *paramtwo = is_a_register(champion, *paramtwo, op->codingbyte.p3);
    return 0;
}

int sub_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int paramthree = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    paramthree = get_params(global, champion, op, op->codingbyte.p2);
    if (sub2_command(&paramone, &paramtwo, champion, op) == -1)
        return -1;
    if (op->codingbyte.p2 == 0b01) {
        if (paramthree < 1 || paramthree > REG_NUMBER)
            return -1;
        champion->reg[paramthree - 1] = paramone - paramtwo;
    } else
        global->map[champion->pc + paramthree % IDX_MOD] =
            paramone - paramtwo;
    return sub3_command(champion, paramthree);
}
