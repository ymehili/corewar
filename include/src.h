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
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/stat.h>

typedef struct global_s global_t;
typedef struct champion_s champion_t;

typedef struct instruction_s {
    int code;
    int nb_arg;
    int type[4];
    int size;
    int cycle;
    int carry;
    void (*fct)(champion_t *champion, global_t *global);
} instruction_t;

typedef struct champion_s {
    int id;
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    char *code;
    int size;
    int address;
    int alive;
    int last_live;
    int nb_live;
    int carry;
    int reg[REG_NUMBER];
    instruction_t *instructions;
    struct champion_s *next;
} champion_t;

typedef struct global_s {
    champion_t *champions;
    int nb_champion;
    int cycle_to_die;
    int cycle;
} global_t;

void *my_memset(void *s, int c, size_t n);
int read_bfile(const char *filename, char **buffer, int *size);
void storebuffer(char *buffer, global_t *global, champion_t *tmp);

#endif /* !SRC_H_ */
