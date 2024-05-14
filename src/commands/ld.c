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
// int ldd_command(global_t *global, champion_t *champion, pc_t *op)
// {
//     int result = 0;
//     int pos = 0;
//     int paramone = get_params(global, champion, op, op->codingbyte.p4);
//     champion->pc += 1;
//     int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
//     printf("paramone: %d\n", paramone);
//     printf("paramtwo: %d\n", paramtwo);
//     pos = paramtwo - 1;
//     if (pos < 0)
//         pos = pos + MEM_SIZE;
//     printf("pos: %d\n", pos);
//     result = champion->pc + paramone % IDX_MOD;
//     champion->reg[pos] = global->map[result];
//     printf("champions reg %d\n",champion->reg[pos]);
//     if (champion->reg[pos] == 0)
//         champion->carry = 1;
//     else
//         champion->carry = 0;
//     champion->wait += 5;
//     champion->pc += 1;
//     return 0;
// }

int ld_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;

    paramone = get_params(global, champion, op, op->codingbyte.p4);
    champion->pc += 1;
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    printf("paramone: %d\n", paramone);
    printf("paramtwo: %d\n", paramtwo);
    champion->reg[paramtwo - 1] = global->map[champion->pc + paramone % IDX_MOD];
    printf("champions reg %d\n", champion->reg[paramtwo - 1]);
    if (champion->reg[paramtwo - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->wait += 5;
    champion->pc += 1;
    return 0;
}