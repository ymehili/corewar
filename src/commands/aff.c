/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** aff
*/

#include "../../include/src.h"

int aff_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p4);
    int ascii = 0;

    if (paramone >= 1 && paramone <= REG_NUMBER) {
        ascii = champion->reg[paramone - 1] % 256;
        write(1, &ascii, 1);
    }
    champion->pc += 2;
    return 0;
}
