/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** sti
*/

#include "../../include/src.h"

/**
 * @brief           Stores the value of a register in the memory.
 *
 * @param global    The global state of the program.
 * @param champion  The current champion executing the command.
 * @param op        The current operation containing the parameters.
 * @return          0 if the command executed successfully, otherwise 1.
 */
int sti_command(global_t *global, champion_t *champion, pc_t *op)
{

    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p2);
    int paramthree = get_params(global, champion, op, op->codingbyte.p3);
    champion->pc++;
    champion->pc++;

    global->map[champion->pc + (paramtwo + paramthree) % IDX_MOD] =
        champion->reg[paramone - 1];
    champion->wait += 25;
    return 0;
}
