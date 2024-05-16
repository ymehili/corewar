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
 * @return          0
 */
int ld_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int result = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    printf("paramone: %d\n", paramone);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    printf("paramtwo: %d\n", paramtwo);

    if (op->codingbyte.p4 == 0b10)
        result = paramone;
    else if (op->codingbyte.p4 == 0b11)
        result = global->map[champion->pc + paramone % IDX_MOD];
    champion->reg[paramtwo - 1] = result;
    printf("result %d\n", result);
    printf("champions reg %d\n", champion->reg[paramtwo - 1]);
    if (champion->reg[paramtwo - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->wait += 5;
    champion->pc += 1;
    printf("        IN THE 02 aka ld POS after %02hhx pos %d\n", global->map[champion->pc], champion->pc);
    return 0;
}
