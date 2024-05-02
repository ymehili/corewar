/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** src
*/

#ifndef SRC_H_
    #define SRC_H_
    #include "lib.h"
    #include "op.h"

typedef struct global_s global_t;

typedef struct champion_s {
    int id;
    char *name;
    char *comment;
    char *code;
    int size;
    int address;
    int alive;
    int last_live;
    int nb_live;
    int carry;
    int reg[REG_NUMBER];
    struct champion_s *next;
} champion_t;

typedef struct instruction_s {
    int code;
    int nb_arg;
    int type[4];
    int size;
    int cycle;
    int carry;
    void (*fct)(champion_t *champion, global_t *global);
} instruction_t;

typedef struct championsfile_s {
    FILE *file;
    struct championsfile_s *next;
} championsfile_t;

typedef struct global_s {
    champion_t *champion;
    int nb_champion;
    int cycle_to_die;
    int cycle;
    championsfile_t *championsfile;
} global_t;

#endif /* !SRC_H_ */
