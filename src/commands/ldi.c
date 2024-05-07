/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** ldi
*/

#include "../../include/src.h"

int ldi_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    int paramthree = get_params(global, champion, op, op->codingbyte.p2);
    char *buffer;

    read(champion->reg[paramthree % IDX_MOD], buffer, IND_SIZE);
}
