/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lldi
*/

#include "../../include/src.h"

int lldi_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p2);
    int paramthree = get_params(global, champion, op, op->codingbyte.p3);
    champion->pc += 2;
    champion->wait += 50;
    return 0;
}
