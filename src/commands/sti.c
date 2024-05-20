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
    int paramone = 0;
    int paramtwo = 0;
    int paramthree = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    paramthree = get_params(global, champion, op, op->codingbyte.p2);
    if (paramone < 1 || paramone > REG_NUMBER)
        return -1;
    paramtwo = is_a_register(champion, paramtwo, op->codingbyte.p3);
    paramthree = is_a_register(champion, paramthree, op->codingbyte.p2);
    global->map[(champion->pc + (paramtwo + paramthree) % IDX_MOD) %
        MEM_SIZE] = champion->reg[paramone - 1];
    // champion->wait += 25;
    champion->pc += 1;
    return 0;
}
