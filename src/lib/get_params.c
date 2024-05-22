/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** get_params.c
*/

#include "../../include/src.h"

/**
 * @brief Reads 2 bytes from the memory map and combines them into a
 *        16-bit integer.
 *
 * @param global    The global state of the program.
 * @param address   The starting address to read from.
 * @return          The 16-bit integer value read from memory.
 */
int16_t read_2_bytes(global_t *global, int address)
{
    int16_t value = 0;
    for (int i = 0; i < 2; i++) {
        value = (value << 8) | global->map[(address + i) % MEM_SIZE];
    }
    return value;
}

void write_in_4_bytes(global_t *global, int address, int value)
{
    uint8_t byte_value = 0;
    int current_address = 0;

    for (int i = 0; i < 4; i++) {
        current_address = (address + i) % MEM_SIZE;
        byte_value = (value >> (8 * (3 - i))) & 0xFF;
        if (global->map[current_address] == 0x00 || byte_value != 0x00)
            global->map[current_address] = byte_value;
    }
}

/**
 * @brief Reads 4 bytes from the memory map and combines
 *        them into a 32-bit integer.
 *
 * @param map       The memory map to read from.
 * @param address   The starting address to read from.
 * @param mem_size  The size of the memory map.
 * @return          The 32-bit integer value read from memory.
 */
int read_4_bytes(global_t *global, int address)
{
    int32_t value = 0;

    for (int i = 0; i < 4; i++)
        value = (value << 8) | global->map[(address + i) % MEM_SIZE];
    return value;
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
