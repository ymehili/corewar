/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** or
*/

#include "../../include/src.h"

int or(global_t *global, champion_t *champion)
{
    int value = 0;
    int reg = 0;
    int pc = champion->pc;
    int i = 0;

    value = get_direct(global, champion, 4);
    reg = get_register(global, champion, 5);
    champion->reg[reg - 1] = value;
    champion->carry = value == 0 ? 1 : 0;
    champion->pc = champion->pc + 6;
    return 0;
}
