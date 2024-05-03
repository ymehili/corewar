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
 * @param op_codingbyte 4 values to represente the codingbyte with 4 possibilites
 *                      00 : 01 : 10 : 11 (who is print 0 : 1 : 2 : 3)
 *                      it show if it's a register, direct, indirect etc
 * @param op_param      it's a array of size 2 who contains all the parameters of the function
 *                      (j'ai pas très bien compris psq cq devrait print
 *                      01 00 07 00 01 01 les args de l'opcode quoi mais a voir lundi)
 *  
 */
static void print_debug(pc_t *op)
{
    printf("opcode (%02x)\n", op->opcode);
    printf("codingbyte 1(%01x)\n", op->codingbyte.p1);
    printf("codingbyte 2(%01x)\n", op->codingbyte.p2);
    printf("codingbyte 3(%01x)\n", op->codingbyte.p3);
    printf("codingbyte 4(%01x)\n", op->codingbyte.p4);
    printf("params (%s)\n", op->params);
    printf("params 2 (%02x)\n", op->params[1]);
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
    return 10; // test return the sti function
    // todo comparaison between hexa and str to find the command
    for (int i = 0 ; i < NB_COMMAND; i++) {
        if (my_strcmp(op->opcode, global->commands[i]) == 0)
            return i;
    }
    return -1;
}

/**
 * @brief       create a structure of the command and start this one
 *
 * @param struct_op  this struct pc_t (not op) is a pointer to the position of a commant (example 0 for the first job
 *                   the struct add automatically all the bytes (without malloc) to his parameters
 *
 * @param all_command Its the array that pointing all the functions

 * @return      return the result of the command
 */
int new_op(global_t *global, champion_t *tmp,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *))
{
    int pointer_command = 0;
    pc_t *op = (pc_t *)&global->map[tmp->pc];

    print_debug(op);
    pointer_command = wich_job(op, global);
    if (pointer_command != -1) {
        return (all_command[pointer_command](global, tmp));
    }
}


/**
 * @todo  - Function to find with codingbyte type is (Just switch case etc)
 *        - add swap bigindian to littlebigindia (just reverse codingbyte.p1 with p2 etc)
 *          askip je crois c'est aussi simple
 *        - start the command with the good parameters
 * Voila en gros ca ça doit etre le début de la vidéo et cette manière la ca devrait permettre
 * de coder plus simplement chaque fonction et d'avancer mieux dans les bytes après
 * A voir comment t'es à l'aise avec le code la est si tu le comprend et si tu t'y retrouve dans 
 * la video mais on pourra retourner vers nathan de toute facon
 * 
*/