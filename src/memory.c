/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** memory.c
*/

#include "../include/src.h"

/**
 * @brief               print parameters to understand
 *
 * @param op_opcode     It's the opcode name
 * @param op_codingbyte 4 values to represente the codingbyte (4 ways)
 *                      00 : 01 : 10 : 11 (who is print 0 : 1 : 2 : 3)
 *                      it show if it's a register, direct, indirect etc
 * @param op_param      it's a array of size 2 who contains all the parameters
 *                      of the function
 *                      (j'ai pas très bien compris psq ca devrait print
 *                      01 00 07 00 01 les args de l'opcode)
 *
 */
static void print_debug(pc_t *op)
{
    printf("opcode (%02x)\n", op->opcode);
    printf("codingbyte 1(%02b)\n", op->codingbyte.p1);
    printf("codingbyte 2(%02b)\n", op->codingbyte.p2);
    printf("codingbyte 3(%02b)\n", op->codingbyte.p3);
    printf("codingbyte 4(%02b)\n", op->codingbyte.p4);
}

/**
 * @brief           Find wich job we need to execute
 *
 * @param op        The struct that contains all the command informations
 * @param global    The global structure containing game data.

 * @return          return the position of the function or -1 if not
 */
static int wich_job(pc_t *op, global_t *global)
{
    for (int i = 0; i < NB_COMMAND; i++) {
        if (op->opcode && op->opcode == global->commands[i])
            return i;
    }
    return -1;
}

/**
 * @brief       create a structure of the command and start this one
 *
 * @param struct_op  this struct pc_t (not op) is a pointer to the position of
 *                   a command (example 0 for the first job
 *                   the struct add automatically all the bytes
 *                   (without malloc) to his parameters
 *
 * @param all_command Its the array that pointing all the functions

 * @return      return the result of the command
 */
int new_op(global_t *global, champion_t *tmp,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    int pointer_command = 0;
    pc_t *op = (pc_t *)&global->map[tmp->pc];

    print_debug(op);
    pointer_command = wich_job(op, global);
    if (pointer_command != -1) {
        return (all_command[pointer_command](global, tmp, op));
    }
    return 0;
}
