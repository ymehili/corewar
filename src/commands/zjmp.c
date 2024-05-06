/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** zjmp
*/

#include "../../include/src.h"

int zjmp(global_t *global, champion_t *champion, pc_t *op)
{
    int value = 0;
    int reg = 0;
    int pc = champion->pc;
    int i = 0;

    value = get_direct(global, champion, 2);
    if (champion->carry == 1) {
        champion->pc = champion->pc + (value % IDX_MOD);
    } else {
        champion->pc = champion->pc + 3;
    }
    return 0;
}
