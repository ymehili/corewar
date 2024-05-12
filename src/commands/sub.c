/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** sub
*/

#include "../../include/src.h"

/**
 * @brief           Subtracts the values of two parameters and stores the
 *                  result in a register.
 *
 * @param global    The global structure containing the state of the program.
 * @param champion  The champion structure representing the current champion.
 * @param op        The pc_t structure representing the current program
 *                  counter.
 * @return          0 indicating successful execution of the sub_command.
 */
int sub_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p4);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    int paramthree = get_params(global, champion, op, op->codingbyte.p2);
    int result = paramone - paramtwo;

    champion->reg[paramthree - 1] = result;
    if (result == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->wait += 10;
    champion->pc += 2;
    return 0;
}
