/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lldi
*/

#include "../../include/src.h"

static int lgi(global_t *global, champion_t *champion,
    int address, int paramthree)
{
    int32_t value = 0;

    if (paramthree < 1 || paramthree > REG_NUMBER)
        return 1;
    value = read_4_bytes(global, address);
    champion->reg[paramthree - 1] = value;
    champion->pc += 1;
    if (value == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    return 0;
}

/**
 * @brief           Loads a value from memory using indirect addressing and
 *                  stores it in a register.
 *
 * @param global    The global state of the program.
 * @param champion  The current champion executing the command.
 * @param op        The current operation containing the parameters.
 * @return          0 if the command executed successfully, otherwise 1.
 */
int lldi_command(global_t *global, champion_t *champion, pc_t *op)
{
    int one = 0;
    int paramtwo = 0;
    int three = 0;
    int sum = 0;
    int pc_copy = champion->pc;

    champion->pc += 1;
    one = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    three = get_params(global, champion, op, op->codingbyte.p2);
    if (op->codingbyte.p4 == 0b01) {
        one = is_a_register(champion, one, op->codingbyte.p4);
    } else if (op->codingbyte.p4 == 0b11)
        one = read_2_bytes(global, (pc_copy + one % IDX_MOD) % MEM_SIZE);
    if (op->codingbyte.p3 == 0b01)
        paramtwo = is_a_register(champion, paramtwo, op->codingbyte.p3);
    sum = one + paramtwo;
    return lgi(global, champion, (pc_copy + sum % IDX_MOD) % MEM_SIZE, three);
}
