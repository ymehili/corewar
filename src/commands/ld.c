/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** ld
*/

#include "../../include/src.h"

/**
 * @brief           Loads a value from memory into a register.
 *
 * @param global    The global state of the program.
 * @param champion  The current champion executing the command.
 * @param op        The current operation being executed.
 * @return          0 if successful, -1 otherwise.
 */
int ld_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p4);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p3);

    champion->reg[paramtwo - 1] = champion->pc + paramone % IDX_MOD;
    champion->wait += 5;
    champion->pc += 3;
    return 0;
}
