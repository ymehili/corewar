/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** src
*/

#ifndef SRC_H_
    #define SRC_H_
    #define NB_COMMAND 17
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
    struct champion_s *next;
} champion_t;

typedef struct coding_s {
    unsigned char p1:2;
    unsigned char p2:2;
    unsigned char p3:2;
    unsigned char p4:2;
} coding_t;
typedef struct pc_s {
    unsigned char opcode;
    struct coding_s codingbyte;
    char params[1];
} pc_t;
typedef struct global_s {
    struct champion_t *champions;
    int nb_champion;
    int cycle_to_die;
    int cycle;
    char *map;
    char *commands;
    struct pc_s pc;
} global_t;

void *my_memset(void *s, int c, size_t n);
int read_bfile(const char *filename, char **buffer, int *size);
void storebuffer(char *buffer, global_t *global, champion_t *tmp);

int add(global_t *global, champion_t *champion, pc_t *op);
int aff(global_t *global, champion_t *champion, pc_t *op);
int and(global_t *global, champion_t *champion, pc_t *op);
int fork_func(global_t *global, champion_t *champion, pc_t *op);
int ld(global_t *global, champion_t *champion, pc_t *op);
int ldi(global_t *global, champion_t *champion, pc_t *op);
int lldi(global_t *global, champion_t *champion, pc_t *op);
int lfork(global_t *global, champion_t *champion, pc_t *op);
int live(global_t *global, champion_t *champion, pc_t *op);
int lld(global_t *global, champion_t *champion, pc_t *op);
int or(global_t *global, champion_t *champion, pc_t *op);
int st(global_t *global, champion_t *champion, pc_t *op);
int sti(global_t *global, champion_t *champion, pc_t *op);
int sub(global_t *global, champion_t *champion, pc_t *op);
int xor(global_t *global, champion_t *champion, pc_t *op);
int zjmp(global_t *global, champion_t *champion, pc_t *op);

int get_register(global_t *global, champion_t *champion, int size);
int get_direct(global_t *global, champion_t *champion, int size);
int get_params(char param);


void create_map(global_t *global);
void launch_game(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *));
int new_op(global_t *global, champion_t *tmp,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *));

#endif /* !SRC_H_ */
