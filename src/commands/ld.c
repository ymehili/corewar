/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** ld
*/

#include "../../include/src.h"

#include <stdint.h>

/**
 * @brief Reads 4 bytes from the memory map and combines them into a 32-bit integer.
 *
 * @param map       The memory map to read from.
 * @param address   The starting address to read from.
 * @param mem_size  The size of the memory map.
 * @return          The 32-bit integer value read from memory.
 */
int read_4_bytes(global_t *global, int address) {
    int value = 0;
    for (int i = 0; i < 4; i++) {
        value = (value << 8) | global->map[(address + i) % MEM_SIZE];
    }
    return value;
}


static int ld2_command(champion_t *champion, int paramtwo)
{
    if (champion->reg[paramtwo - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += 1;
    return 0;
}

/**
 * @brief           Loads a value from memory into a register.
 *
 * @param global    The global state of the program.
 * @param champion  The current champion executing the command.
 * @param op        The current operation being executed.
 * @return          0
 */
int ld_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int32_t result = 0;
    int pc_copy = champion->pc;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    if (paramtwo < 1 || paramtwo > REG_NUMBER)
        return 0;

    if (op->codingbyte.p4 == 0b10) {
        result = paramone;
    } else if (op->codingbyte.p4 == 0b11) {
        result = read_4_bytes(global, (pc_copy + paramone % IDX_MOD) % MEM_SIZE);
    }
    champion->reg[paramtwo - 1] = result;
    return ld2_command(champion, paramtwo);
}

