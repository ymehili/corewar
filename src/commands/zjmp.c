/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** zjmp
*/

#include "../../include/src.h"

int zjmp_command(global_t *global, champion_t *champion, pc_t *op)
{
    short paramone = 0;

    if (champion->carry == 1) {
        paramone = get_indirect(global, champion, op);
        champion->pc -= 2;
        champion->pc = (champion->pc + paramone % IDX_MOD) % MEM_SIZE;
    }
    return 1;
}
