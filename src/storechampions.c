/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** storechampions
*/

#include "../include/src.h"

/**
 * @brief   Initializes a new champion.
 *
 * @return  A pointer to the newly initialized champion.
 */
static champion_t *initchampion(void)
{
    static int id = 0;
    champion_t *champion = malloc(sizeof(champion_t));

    champion->id = id;
    id++;
    champion->name = malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
    champion->comment = malloc(sizeof(char) * COMMENT_LENGTH + 1);
    champion->size = 0;
    champion->address = 0;
    champion->alive = 0;
    champion->last_live = 0;
    champion->nb_live = 0;
    champion->carry = 0;
    for (int i = 0; i < REG_NUMBER; i++)
        champion->reg[i] = 0;
    champion->instructions = NULL;
    champion->next = NULL;
    return champion;
}

static void getheader(champion_t *champion, char *buffer, int *i)
{
    return;
}

static void getchampioninfos(champion_t *champion, char *buffer)
{
    int i = 4;
    int n = 10;

    getheader(champion, buffer, &i);
    return;
}

/**
 * @brief           Stores a buffer into the global champion list.
 *
 * @param buffer    The buffer to be stored.
 * @param global    The global structure containing the champion list.
 * @param tmp       A temporary champion structure used for iteration.
 */
void storebuffer(char *buffer, global_t *global, champion_t *tmp)
{
    if (global->champion == NULL) {
        global->champion = malloc(sizeof(champion_t));
        tmp = global->champion;
    } else {
        while (tmp != NULL)
            tmp = tmp->next;
        tmp = malloc(sizeof(champion_t));
    }
    tmp = initchampion();
    global->nb_champion++;
    getchampioninfos(tmp, buffer);
}
