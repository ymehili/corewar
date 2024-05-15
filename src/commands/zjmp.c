/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** zjmp
*/

#include "../../include/src.h"

int zjmp_command(global_t *global, champion_t *champion, pc_t *op)
{
    // champion->pc += 1;
    short paramone = 0;

    printf("pc before : %d\n", champion->pc);
    if (champion->carry == 1) {
        paramone = get_indirect(global, champion, op);
        champion->pc -= 2;
        printf("champion pc %d paramone %hd \n", champion->pc, paramone);
        champion->pc = (champion->pc + paramone % IDX_MOD);
        printf("pc after : %d\n", champion->pc);
    } else {
        printf("pc else : %d\n", champion->pc);
    }
    champion->wait += 20;
    printf("pc at the end : %d\n", champion->pc);
    return 1;
}
