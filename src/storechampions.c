/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** storechampions
*/

#include "../include/src.h"

int find_first_free_id(global_t *global)
{
    int id = 1;
    champion_t *tmp = global->champions;

    while (tmp != NULL) {
        if (tmp->id == id) {
            id++;
            tmp = global->champions;
        } else
            tmp = tmp->next;
    }
    return id;
}

/**
 * @brief   Initializes a new champion.
 *
 * @return  A pointer to the newly initialized champion.
 */
static void init_champ2(global_t *global, champion_t *champion)
{
    champion->last_live = 0;
    champion->nb_live = 0;
    champion->carry = 0;
    for (int i = 0; i < REG_NUMBER; i++)
        champion->reg[i] = 0;
    champion->reg[0] = champion->id;
    champion->clone_next = NULL;
    champion->clone_prev = NULL;
    champion->next = NULL;
}

static champion_t *initchampion(global_t *global)
{
    static int id = 1;
    champion_t *champion = malloc(sizeof(champion_t));

    champion->to_exec = 0;
    champion->id = id;
    if (global->prog_number != -1)
        champion->id = global->prog_number;
    else
        champion->id = find_first_free_id(global);
    if (global->load_address != -1)
        champion->load_address = global->load_address;
    else
        champion->load_address = -1;
    champion->size = 0;
    champion->pc = 0;
    champion->wait = 1;
    champion->alive = 0;
    init_champ2(global, champion);
    return champion;
}

/**
 * @brief           Retrieves the header information from the buffer and stores
 *                  it in the champion structure.
 *
 * @param champion  A pointer to the champion structure.
 * @param buffer    The buffer containing the program header information.
 * @param i         A pointer to the current index in the buffer.
 */
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
    (*i) += 4;
}

/**
 * @brief           Retrieves the information of a champion from a buffer and
 *                  stores it in a champion structure.
 *
 * @param champion  The champion structure to store the information in.
 * @param buffer    The buffer containing the champion information.
 */
static void getchampioninfos(champion_t *champion, char *buffer)
{
    int i = 4;

    getheader(champion, buffer, &i);
    champion->code = malloc(sizeof(char) * champion->size);
    for (int j = 0; j < champion->size; j++) {
        champion->code[j] = buffer[i];
        i++;
    }
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
    champion_t *new_champion = malloc(sizeof(champion_t));

    new_champion = initchampion(global);
    getchampioninfos(new_champion, buffer);
    if (global->champions == NULL) {
        global->champions = new_champion;
    } else {
        tmp = global->champions;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_champion;
    }
    global->nb_champion++;
}
