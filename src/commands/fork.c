/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** fork
*/

#include "../../include/src.h"

int fork_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p4);

    champion->wait += 800;
    champion->pc++;
    return 0;
}
