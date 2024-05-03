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

typedef struct argument_s {
    int one;
    int two;
    int three;
    int four;
} argument_t;

typedef struct champion_s {
    int id;
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    char *code;
    int size;
    int alive;
    int last_live;
    int nb_live;
    int carry;
    int reg[REG_NUMBER];
    int pc;
    int wait;
    char **commands;
    struct champion_s *next;
} champion_t;

typedef struct global_s {
    struct champion_t *champions;
    int nb_champion;
    int cycle_to_die;
    int cycle;
    char *map;
} global_t;

void *my_memset(void *s, int c, size_t n);
int read_bfile(const char *filename, char **buffer, int *size);
void storebuffer(char *buffer, global_t *global, champion_t *tmp);

int add(global_t *global, champion_t *champion);
int aff(global_t *global, champion_t *champion);
int and(global_t *global, champion_t *champion);
int fork_func(global_t *global, champion_t *champion);
int ld(global_t *global, champion_t *champion);
int ldi(global_t *global, champion_t *champion);
int lldi(global_t *global, champion_t *champion);
int lfork(global_t *global, champion_t *champion);
int live(global_t *global, champion_t *champion);
int lld(global_t *global, champion_t *champion);
int or(global_t *global, champion_t *champion);
int st(global_t *global, champion_t *champion);
int sti(global_t *global, champion_t *champion);
int sub(global_t *global, champion_t *champion);
int xor(global_t *global, champion_t *champion);
int zjmp(global_t *global, champion_t *champion);

int get_register(global_t *global, champion_t *champion, int size);
int get_direct(global_t *global, champion_t *champion, int size);
#endif /* !SRC_H_ */
