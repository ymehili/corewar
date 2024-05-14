/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** fork
*/

#include "../../include/src.h"

void copy_champion(champion_t *dest, champion_t *src)
{
    int i;
    dest->pc = src->pc;
    dest->wait = src->wait;
    dest->carry = src->carry;
    for (i = 0; i < REG_NUMBER; i++) {
        dest->reg[i] = src->reg[i];
    }
}

champion_t *create_champion(champion_t *champion, int new_pc)
{
    champion_t *new_champion = malloc(sizeof(champion_t));

    copy_champion(new_champion, champion);
    new_champion->pc = new_pc;
    return new_champion;
}

int fork_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = get_params(global, champion, op, op->codingbyte.p4);
    int new_pc = (champion->pc + paramone % IDX_MOD + MEM_SIZE) % MEM_SIZE;

    champion_t *new_champion = create_champion(champion, new_pc);
    for(champion_t *tmp = global->champions; tmp; tmp = tmp->next) {
        if (tmp->next == NULL) {
            tmp->next = new_champion;
            break;
        }
    }
    champion->wait += 800;
    champion->pc += 1;
    return 0;
}
