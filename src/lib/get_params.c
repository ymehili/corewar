/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** get_params.c
*/

#include "../../include/src.h"

int get_register(global_t *global, champion_t *champion, pc_t *op)
{
    int reg = global->map[(champion->pc + 1) % MEM_SIZE];

    champion->pc = (champion->pc + 1) % MEM_SIZE;
    printf("register\n");
    return reg;
}

int get_direct(global_t *global, champion_t *champion, pc_t *op)
{
    int direct = (global->map[(champion->pc + 1) % MEM_SIZE] << 24) |
                (global->map[(champion->pc + 2) % MEM_SIZE] << 16) |
                (global->map[(champion->pc + 3) % MEM_SIZE] << 8) |
                global->map[(champion->pc + 4) % MEM_SIZE];

    champion->pc = (champion->pc + 4) % MEM_SIZE;
    printf("direct\n");
    return direct;
}

short get_indirect(global_t *global, champion_t *champion, pc_t *op)
{
    short indirect = (global->map[(champion->pc + 1) % MEM_SIZE] << 8) |
                    global->map[(champion->pc + 2) % MEM_SIZE];

    champion->pc = (champion->pc + 2) % MEM_SIZE;
    printf("indirect\n");
    return indirect;
}

int get_params(global_t *global, champion_t *champion, pc_t *op, char param)
{
    switch (param) {
        case 0b01:
            return get_register(global, champion, op);
            break;
        case 0b10:
            if (op->opcode <= 0x09)
                return get_direct(global, champion, op);
            else
                return (int)get_indirect(global, champion, op);
            break;
        case 0b11:
            return (int)get_indirect(global, champion, op);
            break;
        default:
            break;
    }
    return 0;
}
