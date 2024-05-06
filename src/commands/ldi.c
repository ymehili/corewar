/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** ldi
*/

#include "../../include/src.h"

int ldi(global_t *global, champion_t *champion, pc_t *op)
{
    int value = 0;
    int reg = 0;
    int reg2 = 0;
    int pc = champion->pc;
    int i = 0;

    reg = get_register(global, champion, 2);
    reg2 = get_register(global, champion, 3);
    value = champion->reg[reg - 1] + champion->reg[reg2 - 1];
    reg = get_register(global, champion, 4);
    champion->reg[reg - 1] = value;
    champion->carry = value == 0 ? 1 : 0;
    champion->pc = champion->pc + 5;
    return 0;
}
