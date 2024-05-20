/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** live
*/

#include "../../include/src.h"

/**
 * @brief           Sets the champion's alive flag to 1 and updates the
 *                  champion's last live cycle.
 *
 * @param global    The global state of the program.
 * @param champion  The champion executing the command.
 * @param op        The process control containing the register value.
 * @return          0 indicating successful execution of the command.
 */
int live_command(global_t *global, champion_t *champion, pc_t *op)
{
    get_direct(global, champion, op);
    champion->pc++;
    champion->alive++;
    champion->last_live = global->cycle;
    // champion->wait += 10;
    global->live_count++;
    return 0;
}
