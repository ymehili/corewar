/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** st
*/

#include "../../include/src.h"

/**
 * @brief           Stores the value of a register in the memory.
 *
 * @param global    The global state of the program.
 * @param champion  The current champion executing the command.
 * @param op        The current operation containing the parameters.
 * @return          0 if the command executed successfully, otherwise -1.
 */
int st_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int address = 0;
    int pc_copy = champion->pc + 2;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    if (paramone < 1 || paramone > REG_NUMBER)
        return -1;
    paramone = is_a_register(champion, paramone, op->codingbyte.p4);

    if (op->codingbyte.p3 == 0b01) {
        if (paramtwo < 1 || paramtwo > REG_NUMBER)
            return -1;
        champion->reg[paramtwo - 1] = paramone;
    } else {
        address = (pc_copy + paramtwo % IDX_MOD) % MEM_SIZE;
        write_in_4_bytes(global, address, paramone);
        for (int i = 0; i < 4; i++)
            global->colors_map[(address + i) % MEM_SIZE] = champion->id + 1;
    }
    champion->pc += 1;
    return 0;
}

