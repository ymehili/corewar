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
    int paramone = 0;
    int paramtwo = 0;
    int paramthree = 0;
    int val_paramone = 0;
    int val_paramtwo = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    paramthree = get_params(global, champion, op, op->codingbyte.p2);
    val_paramone = champion->reg[paramone - 1];
    val_paramtwo = champion->reg[paramtwo - 1];
    if (op->codingbyte.p2 == 0b01)
        champion->reg[paramthree - 1] = val_paramone + val_paramtwo;
    else
        global->map[champion->pc + paramthree % IDX_MOD] =
            val_paramone + val_paramtwo;
    if (champion->reg[paramthree - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += 1;
    champion->wait += 10;
    return 0;
}
