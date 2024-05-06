/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lfork
*/

#include "../../include/src.h"

int lfork(global_t *global, champion_t *champion, pc_t *op)
{
    int value = 0;
    int reg = 0;
    int pc = champion->pc;
    int i = 0;

    value = get_direct(global, champion, 2);
    reg = get_register(global, champion, 3);
    champion->reg[reg - 1] = value;
    champion->carry = value == 0 ? 1 : 0;
    champion->pc = champion->pc + 3;
    return 0;
}
