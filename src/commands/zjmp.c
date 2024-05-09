/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** zjmp
*/

#include "../../include/src.h"

int zjmp_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p4);

    if (champion->carry == 1){
        champion->pc = (champion->pc + paramone) % IDX_MOD;
        return 0;
    }
    champion->wait += 3;
    return 1;
}
