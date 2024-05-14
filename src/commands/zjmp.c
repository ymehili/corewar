/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** zjmp
*/

#include "../../include/src.h"

// int zjmp_command(global_t *global, champion_t *champion, pc_t *op)
// {
//     int paramone = get_params(global, champion, op, op->codingbyte.p4);
//     printf("paramone: %d\n", paramone);
//     printf("pc: %d\n", champion->pc);
//     if (champion->carry == 1){
//         champion->pc = champion->pc + paramone % IDX_MOD;
//         printf("pc after : %d\n", champion->pc);
//     } else  {
//         champion->pc += 3;
//         printf("pc else : %d\n", champion->pc);
//     }
//     if (champion->pc >= MEM_SIZE)
//         champion->pc = champion->pc - MEM_SIZE;
//     if (champion->pc < 0)
//         champion->pc = champion->pc + MEM_SIZE;
//     champion->wait += 3;
//     printf("pc at the end : %d\n", champion->pc);
//     return 1;
// }

int zjmp_command(global_t *global, champion_t *champion, pc_t *op)
{
    // champion->pc += 1;
    short paramone = 0;
    printf("paramone %hd\n", paramone);

    printf("pc before : %d\n", champion->pc);
    if (champion->carry == 1) {
        paramone = get_indirect(global, champion, op);
        champion->pc = (champion->pc + paramone % IDX_MOD) % MEM_SIZE;
        printf("pc after : %d\n", champion->pc);
    } else {
        printf("pc else : %d\n", champion->pc);
    }
    champion->wait += 20;
    printf("pc at the end : %d\n", champion->pc);
    return 1;
}
