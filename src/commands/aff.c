/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** aff
*/

#include "../../include/src.h"

int aff_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);

    champion->pc += 2;
    return 0;
}
