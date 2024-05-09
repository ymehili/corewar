/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** ldi
*/

#include "../../include/src.h"

int ldi_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p4);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    int paramthree = get_params(global, champion, op, op->codingbyte.p2);

    champion->wait += 25;
    champion->pc += 2;
    return 0;
}
