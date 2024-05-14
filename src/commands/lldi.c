/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lldi
*/

#include "../../include/src.h"

int lldi_command(global_t *global, champion_t *champion, pc_t *op)
{
    int paramone = 0;
    int paramtwo = 0;
    int paramthree = 0;
    int val_paramone = 0;
    int val_paramtwo = 0;
    int address = 0;
    int ind_value = 0;
    int result = 0;

    champion->pc += 1;
    paramone = get_params(global, champion, op, op->codingbyte.p4);
    paramtwo = get_params(global, champion, op, op->codingbyte.p3);
    paramthree = get_params(global, champion, op, op->codingbyte.p2);
    if (op->codingbyte.p4 == 0b01)
        val_paramone = champion->reg[paramone - 1];
    else
        val_paramone = paramone;
    if (op->codingbyte.p3 == 0b01)
        val_paramtwo = champion->reg[paramtwo - 1];
    else
        val_paramtwo = paramtwo;
    address = (champion->pc + val_paramone) % MEM_SIZE;
    if (address < 0)
        address += MEM_SIZE;
    for (int i = 0; i < IND_SIZE; ++i)
        ind_value = (ind_value << 8) | global->map[(address + i) % MEM_SIZE];
    address = (champion->pc + (ind_value + val_paramtwo)) % MEM_SIZE;
    if (address < 0)
        address += MEM_SIZE;
    for (int i = 0; i < REG_SIZE; ++i)
        result = (result << 8) | global->map[(address + i) % MEM_SIZE];
    champion->reg[paramthree - 1] = result;

    if (champion->reg[paramthree - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->wait += 50;
    champion->pc += 1;
    return 0;
}
