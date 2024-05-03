/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** add
*/

#include "../../include/src.h"

int add(global_t *global, champion_t *champion)
{
    int reg1 = 0;
    int reg2 = 0;
    int reg3 = 0;
    int pc = champion->pc;
    int i = 0;
    reg1 = global->map[champion->pc + 2];
    reg1 = global->map[champion->pc + 3];
    reg1 = global->map[champion->pc + 4];
    reg1 = get_register(global, champion, 4);
    reg2 = get_register(global, champion, 5);
    reg3 = get_register(global, champion, 6);
    champion->reg[reg3 - 1] = champion->reg[reg1 - 1] + champion->reg[reg2 - 1];
    champion->carry = champion->reg[reg3 - 1] == 0 ? 1 : 0;
    champion->pc = champion->pc + 7;
    return 0;
}