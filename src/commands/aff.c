/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** aff
*/

#include "../../include/src.h"

int aff_command(global_t *global, champion_t *champion, pc_t *op)
{
    int ascii = 0;
    int paramone = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    ascii = champion->reg[paramone - 1] % 256;
    mini_printf("char : %c with is ascci %d\n", ascii, ascii);
    champion->pc += 1;
    champion->wait += 2;
    return 0;
}
