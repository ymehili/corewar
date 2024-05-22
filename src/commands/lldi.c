/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lldi
*/

#include "../../include/src.h"

static int lldi4_command(int result, global_t *global,
    champion_t *champion, int paramthree)
{
    champion->reg[paramthree - 1] = result;
    if (champion->reg[paramthree - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += 1;
    return 0;
}

static void lldi3_command(int *address, int ind_value, int paramtwo,
    champion_t *champion)
{
    *address = (champion->pc + ((ind_value + paramtwo))) % MEM_SIZE;
    if (*address < 0)
        *address += MEM_SIZE;
}

static void lldi2_command(int *address, int ind_value,
    int paramtwo, global_t *global)
{
    if (*address < 0)
        *address += MEM_SIZE;
    for (int i = 0; i < IND_SIZE; ++i)
        ind_value = (ind_value << 8) | global->map[(*address + i) % MEM_SIZE];
}

int lldi_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int paramthree = 0;
    int address = 0;
    int ind_value = 0;
    int result = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    paramthree = get_params(global, champion, op, op->codingbyte.p2);
    paramone = is_a_register(champion, paramone, op->codingbyte.p4);
    paramtwo = is_a_register(champion, paramtwo, op->codingbyte.p3);
    address = (champion->pc + (paramone)) % MEM_SIZE;
    lldi2_command(&address, ind_value, paramtwo, global);
    lldi3_command(&address, ind_value, paramtwo, champion);
    for (int i = 0; i < REG_SIZE; ++i)
        result = (result << 8) | global->map[(address + i) % MEM_SIZE];
    return lldi4_command(result, global, champion, paramthree);
}
