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

    printf("in the pc before there is: %02hhx\n", global->map[champion->pc]);
    int paramone = get_params(global, champion, op, op->codingbyte.p4);
    printf("in the pc param1 there is: %02hhx\n", global->map[champion->pc]);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    printf("in the pc param2 there is: %02hhx\n", global->map[champion->pc]);
    int paramthree = get_params(global, champion, op, op->codingbyte.p2);
    printf("in the pc param3 there is: %02hhx\n", global->map[champion->pc]);

    champion->pc++;
    printf("in the pc durig the mapping there is: %02hhx\n", global->map[champion->pc]);
    global->map[champion->pc + paramtwo + paramthree % IDX_MOD] =
        champion->reg[paramone - 1];
    champion->wait += 25;
    printf("in the pc after there is: %02hhx\n", global->map[champion->pc]);
    return 0;
}
