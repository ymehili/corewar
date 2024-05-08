/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** add
*/

#include "../../include/src.h"

/**
 * @brief           adds the values of two parameters and stores the result in
 *                  a register.
 *
 * @param global    The global structure containing the state of the program.
 * @param champion  The champion structure representing the current champion.
 * @param op        The pc_t structure representing the current program
 *                  counter.
 * @return          0 indicating successful execution of the add command.
 */
int add_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p1);
    int paramtwo = get_params(global, champion, op, op->codingbyte.p2);
    int paramthree = get_params(global, champion, op, op->codingbyte.p3);

    champion->reg[paramthree - 1] = paramone + paramtwo;
    champion->wait += 10;
    return 0;
}
