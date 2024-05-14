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
    champion->pc += 1;
    printf("champion pc %d\n", champion->pc);
    int paramone = get_params(global, champion, op, op->codingbyte.p4);
    printf("paramone: %d\n", paramone);
    printf("champion pc1 %d\n", champion->pc);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    printf("paramtwo: %d\n", paramtwo);
    printf("champion pc2 %d\n", champion->pc);
    int paramthree = get_params(global, champion, op, op->codingbyte.p2);
    printf("paramthree: %d\n", paramthree);
    printf("champion pc3 %d\n", champion->pc);
    champion->pc += 1;
    printf("champion pc4 %d\n", champion->pc);
    global->map[champion->pc + paramtwo + paramthree % IDX_MOD] =
        champion->reg[paramone - 1];
    champion->wait += 25;
    return 0;
}
