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
    if (champion->clone_next != NULL) {
        printf("LE PC 0(%s) DANS LA COMMANDE D'AVANT %d, ADRESSE PC: %p\n", champion->name, champion->clone_next->pc, (void*)&(champion->clone_next->pc));
    }
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
    if (paramone < 1 || paramone > REG_NUMBER) {
        fprintf(stderr, "Error: Invalid register %d\n", paramone);
        return -1;
    }
    if (champion->clone_next != NULL) {
        printf("LE PC 1(%s) DANS LA COMMANDE D'AVANT %d, ADRESSE PC: %p\n", champion->name, champion->clone_next->pc, (void*)&(champion->clone_next->pc));
    }
    paramtwo = is_a_register(champion, paramtwo, op->codingbyte.p3);
    paramthree = is_a_register(champion, paramthree, op->codingbyte.p2);
    if (champion->clone_next != NULL) {
        printf("LE PC 2(%s) DANS LA COMMANDE D'AVANT %d, ADRESSE PC: %p\n", champion->name, champion->clone_next->pc, (void*)&(champion->clone_next->pc));
    }
    global->map[champion->pc + paramtwo + paramthree % IDX_MOD] =
        champion->reg[paramone - 1];
    printf("map[%d] = reg : %d [%d]\n", champion->pc + (paramtwo + paramthree) % IDX_MOD, paramone,
        champion->reg[paramone - 1]);
    if (champion->clone_next != NULL) {
        printf("LE PC 3(%s) DANS LA COMMANDE D'AVANT %d, ADRESSE PC: %p\n", champion->name, champion->clone_next->pc, (void*)&(champion->clone_next->pc));
    }
    if (champion->clone_next != NULL) {
        printf("LE PC 4(%s) DANS LA COMMANDE D'AVANT %d, ADRESSE PC: %p\n", champion->name, champion->clone_next->pc, (void*)&(champion->clone_next->pc));
    }
    champion->wait += 25;
    champion->pc += 1;
    printf("champion pc4 %d\n", champion->pc);
    if (champion->clone_next != NULL) {
        printf("LE PC 5(%s) DANS LA COMMANDE D'AVANT %d, ADRESSE PC: %p\n", champion->name, champion->clone_next->pc, (void*)&(champion->clone_next->pc));
    }
    return 0;
}


// int sti_command(global_t *global, champion_t *champion, pc_t *op)
// {

//     champion->pc += 1;
//     int paramone = get_params(global, champion, op, op->codingbyte.p4);
//     int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
//     int paramthree = get_params(global, champion, op, op->codingbyte.p2);
    
//     paramtwo = is_a_register(champion, paramtwo, op->codingbyte.p3);
//     paramthree = is_a_register(champion, paramthree, op->codingbyte.p2);
//     global->map[champion->pc + paramtwo + paramthree % IDX_MOD] =
//         champion->reg[paramone - 1];
//     champion->wait += 25;
//     champion->pc += 1;
//     return 0;
// }


// int sti_command(global_t *global, champion_t *champion, pc_t *op)
// {
//     champion->pc += 1;

//     // Retrieve parameters
//     int paramone = get_params(global, champion, op, op->codingbyte.p4);
//     int paramtwo = get_params(global, champion, op, op->codingbyte.p3);
//     int paramthree = get_params(global, champion, op, op->codingbyte.p2);

//     // Validate that paramone is a valid register
//     if (paramone < 1 || paramone > REG_NUMBER) {
//         fprintf(stderr, "Error: Invalid register %d\n", paramone);
//         return -1;
//     }

//     // Validate and possibly dereference registers for paramtwo and paramthree
//     paramtwo = is_a_register(champion, paramtwo, op->codingbyte.p3);
//     paramthree = is_a_register(champion, paramthree, op->codingbyte.p2);

//     // Calculate the target position
//     int target_pos = (champion->pc + (paramtwo + paramthree) % IDX_MOD) % MEM_SIZE;
//     if (target_pos < 0) {
//         target_pos += MEM_SIZE;
//     }

//     // DBG_PRINT("paramone: %d, paramtwo: %d, paramthree: %d\n", paramone, paramtwo, paramthree);
//     // DBG_PRINT("Writing value %d to map position %d\n", champion->reg[paramone - 1], target_pos);

//     // Store the value in the calculated position on the map
//     global->map[target_pos] = champion->reg[paramone - 1];

//     // Adjust the champion's wait time and pc
//     champion->wait += 25;
//     champion->pc += 1;

//     return 0;
// }