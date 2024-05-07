/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** get_params.c
*/

#include "../../include/src.h"

int get_params(char param)
{
    switch (param) {
        case 0b00:
            printf("REG\n");
            break;
        case 0b01:
            printf("DIR\n");
            break;
        case 0b10:
            printf("IND\n");
            break;
        case 0b11:
            printf("LAB\n");
            break;
        default:
            break;
    }
    return 0;
}
