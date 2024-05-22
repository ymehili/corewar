/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** get_params.c
*/

#include "../../include/src.h"

void write_in_4_bytes(global_t *global, int address, int value)
{
    for (int i = 0; i < 4; i++) {
        int current_address = (address + i) % MEM_SIZE;
        uint8_t byte_value = (value >> (8 * (3 - i))) & 0xFF;
        if (global->map[current_address] == 0x00 || byte_value != 0x00) {
            global->map[current_address] = byte_value;
        }
    }
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
