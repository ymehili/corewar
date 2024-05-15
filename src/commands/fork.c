/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** fork
*/

#include "../../include/src.h"

// static void place_champion(champion_t *new_champion, champion_t *champion)
// {
//     for (champion_t *tmp = champion; tmp; tmp = tmp->clone_next)
//         if(tmp->clone_next == NULL) {
//             tmp->clone_next = new_champion;
//             new_champion->clone_prev = tmp;
//             new_champion->clone_next = NULL;
//             break;
//     }
// }

// static champion_t *init_clone_champion(champion_t *champion, int paramone)
// {
//     static int id = 0;
//     champion_t *new_champion = malloc(sizeof(champion_t));

//     champion->pc -= 2;
//     // new_champion->id = id;
//     new_champion->size = champion->size;
//     new_champion->code = my_strdup(champion->code);
//     my_strcpy(new_champion->name, champion->name);
//     my_strcpy(new_champion->comment, champion->comment);
//     new_champion->wait = 1;
//     new_champion->alive = 0;
//     new_champion->last_live = 0;
//     new_champion->nb_live = 0;
//     new_champion->carry = 0;
//     for (int i = 0; i < REG_NUMBER; i++)
//         new_champion->reg[i] = champion->reg[i];
//     place_champion(new_champion, champion);
//     printf("pc: %d\n", new_champion->pc);
//     return champion;
// }

// int fork_command(global_t *global, champion_t *champion, pc_t *op)
// {
//     short paramone = get_indirect(global, champion, op);
//     champion_t *new_champion = init_clone_champion(champion, paramone);

//     new_champion->next = champion->next;
//     printf("paramone: %d\n", paramone);
//     new_champion->pc += champion->pc + paramone % IDX_MOD;
//     printf("result calul: %d\n", champion->pc + paramone % IDX_MOD);
//     printf("new_champion pc: %d\n", new_champion->pc);
//     printf("pos du new_champion %d: %02hhx\n", new_champion->pc, global->map[new_champion->pc]);
//     printf("pos du champion, %d: %02hhx\n", champion->pc, global->map[champion->pc]);
//     champion->wait += 800;
//     champion->pc += 2;
//     return 0;
// }

static void place_champion(champion_t *new_champion, champion_t *champion) {
    for (champion_t *tmp = champion; tmp; tmp = tmp->clone_next) {
        if (tmp->clone_next == NULL) {
            tmp->clone_next = new_champion;
            new_champion->clone_prev = tmp;
            new_champion->clone_next = NULL;
            break;
        }
    }
}

static champion_t *init_clone_champion(champion_t *champion, int paramone) {
    static int id = 0;
    champion_t *new_champion = malloc(sizeof(champion_t));

    // Initialize new_champion's fields
    champion->pc -= 2;
    new_champion->id = id++;
    new_champion->size = champion->size;
    new_champion->code = my_strdup(champion->code);
    my_strcpy(new_champion->name, champion->name);
    my_strcpy(new_champion->comment, champion->comment);
    new_champion->wait = 1;
    new_champion->alive = 0;
    new_champion->last_live = 0;
    new_champion->nb_live = 0;
    new_champion->carry = 0;
    for (int i = 0; i < REG_NUMBER; i++) {
        new_champion->reg[i] = champion->reg[i];
    }

    // Initialize pc to avoid it retaining any garbage value
    new_champion->pc = 0; // Default or initial value
    place_champion(new_champion, champion);

    return new_champion;
}

int fork_command(global_t *global, champion_t *champion, pc_t *op) {
    short paramone = get_indirect(global, champion, op);
    champion_t *new_champion = init_clone_champion(champion, paramone);

    new_champion->next = champion->next;

    // Calculate new_champion's pc correctly
    new_champion->pc = champion->pc + paramone % IDX_MOD;

    // Debug output
    printf("paramone: %d\n", paramone);
    printf("result calul: %d\n", champion->pc + paramone % IDX_MOD);
    printf("new_champion pc: %d\n", new_champion->pc);
    printf("pos du new_champion %d: %02hhx\n", new_champion->pc, global->map[new_champion->pc]);
    champion->pc += 3;
    printf("pos du champion, %d: %02hhx\n", champion->pc, global->map[champion->pc]);

    champion->wait += 800;

    return 0;
}
