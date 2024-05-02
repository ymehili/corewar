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
    for (int j = 0; j < PROG_NAME_LENGTH; j++) {
        champion->name[j] = buffer[*i];
        (*i)++;
    }
    (*i) += 4;
    champion->size = swap_int_bytes(buffer[*i] | (buffer[*i + 1] << 8)
        | (buffer[*i + 2] << 16) | (buffer[*i + 3] << 24));
    (*i) += 4;
    for (int j = 0; j < COMMENT_LENGTH; j++) {
        champion->comment[j] = buffer[*i];
        (*i)++;
    }
}

static void getchampioninfos(champion_t *champion, char *buffer)
{
    int i = 4;

    getheader(champion, buffer, &i);
    printf("name: %s\n", champion->name);
    printf("size: %d\n", champion->size);
    printf("comment: %s\n", champion->comment);
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
    if (global->champions == NULL) {
        global->champions = malloc(sizeof(champion_t));
        tmp = global->champions;
    } else {
        while (tmp != NULL)
            tmp = tmp->next;
        tmp = malloc(sizeof(champion_t));
    }
    tmp = initchampion();
    global->nb_champion++;
    getchampioninfos(tmp, buffer);
}
