/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** get_params.c
*/

#include "../../include/src.h"

int get_register(global_t *global, champion_t *champion, pc_t *op)
{
    int reg = global->map[champion->pc + 1];

    champion->pc += 1;
    return reg;
}

int get_direct(global_t *global, champion_t *champion, pc_t *op)
{
    short direct = global->map[champion->pc + 1] << 8 |
        global->map[champion->pc + 2];

    champion->pc += 2;
    return (int)(swap_short_bytes(direct));
}

int get_indirect(global_t *global, champion_t *champion, pc_t *op)
{
    short indirect = global->map[champion->pc + 1] << 8 |
        global->map[champion->pc + 2];

    champion->pc += 4;
    return (int)(swap_short_bytes(indirect));
}

int get_label(global_t *global, champion_t *champion, pc_t *op)
{
    int label = global->map[champion->pc + 1] << 8 |
        global->map[champion->pc + 2];

    champion->pc += 8;
    return swap_int_bytes(label);
}

int get_params(global_t *global, champion_t *champion, pc_t *op, char param)
{
    switch (param) {
        case 0b00:
            return get_register(global, champion, op);
            break;
        case 0b01:
            return get_direct(global, champion, op);
            break;
        case 0b10:
            return get_indirect(global, champion, op);
            break;
        case 0b11:
            return get_label(global, champion, op);
            break;
        default:
            break;
    }
    return 0;
}
