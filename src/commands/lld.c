/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lld
*/

#include "../../include/src.h"

static int lld2_command(champion_t *champion, int paramtwo)
{
    if (champion->reg[paramtwo - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->wait += 5;
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
int lld_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int result = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    if (paramtwo < 1 || paramtwo > REG_NUMBER)
        return 0;
    if (op->codingbyte.p4 == 0b10)
        result = paramone;
    else if (op->codingbyte.p4 == 0b11)
        result = global->map[champion->pc + paramone];
    champion->reg[paramtwo - 1] = result;
    return lld2_command(champion, paramtwo);
}
