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
    #include <stdint.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Export.h>

typedef struct global_s global_t;
typedef struct champion_s champion_t;

typedef struct champion_s {
    int pc;
    int wait;
    int id;
    int size;
    char *code;
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    int alive;
    int last_live;
    int nb_live;
    int carry;
    int to_exec;
    int load_address;
    struct champion_s *clone_next;
    struct champion_s *clone_prev;
    struct champion_s *next;
    int reg[REG_NUMBER];
} champion_t;

typedef struct coding_s {
    unsigned char p1 : 2;
    unsigned char p2 : 2;
    unsigned char p3 : 2;
    unsigned char p4 : 2;
} coding_t;
typedef struct pc_s {
    unsigned char opcode;
    struct coding_s codingbyte;
    char params[1];
} pc_t;
typedef struct global_s {
    int nb_champion;
    int cycle_to_die;
    int cycle_count_die;
    int cycle;
    int dump;
    int live_count;
    int *colors_map;
    char *map;
    char *commands;
    int flag_print;
    int prog_number;
    int load_address;
    int sleep_time;
    sfRenderWindow *window;
    champion_t *champions;
} global_t;

void *my_memset(void *s, int c, size_t n);
int read_bfile(const char *filename, char **buffer, int *size);
void storebuffer(char *buffer, global_t *global, champion_t *tmp);

int add_command(global_t *global, champion_t *champion, pc_t *op);
int aff_command(global_t *global, champion_t *champion, pc_t *op);
int and_command(global_t *global, champion_t *champion, pc_t *op);
int fork_command(global_t *global, champion_t *champion, pc_t *op);
int ld_command(global_t *global, champion_t *champion, pc_t *op);
int ldi_command(global_t *global, champion_t *champion, pc_t *op);
int lfork_command(global_t *global, champion_t *champion, pc_t *op);
int live_command(global_t *global, champion_t *champion, pc_t *op);
int lld_command(global_t *global, champion_t *champion, pc_t *op);
int lldi_command(global_t *global, champion_t *champion, pc_t *op);
int or_command(global_t *global, champion_t *champion, pc_t *op);
int st_command(global_t *global, champion_t *champion, pc_t *op);
int sti_command(global_t *global, champion_t *champion, pc_t *op);
int sub_command(global_t *global, champion_t *champion, pc_t *op);
int xor_command(global_t *global, champion_t *champion, pc_t *op);
int zjmp_command(global_t *global, champion_t *champion, pc_t *op);

int get_label(global_t *global, champion_t *champion, pc_t *op);
short get_indirect(global_t *global, champion_t *champion, pc_t *op);
int get_direct(global_t *global, champion_t *champion, pc_t *op);
int get_register(global_t *global, champion_t *champion, pc_t *op);
int get_params(global_t *global, champion_t *champion, pc_t *op, char param);

int is_a_register(champion_t *champion, int param, char paramtype);
int is_a_indirect(global_t *global, int pc,
    int param, char paramtype);

void write_in_4_bytes(global_t *global, int address, int value);
int read_4_bytes(global_t *global, int address);
int16_t read_2_bytes(global_t *global, int address);


int process_args(int argc, char const *argv[], global_t *global);
void create_map(global_t *global);
void launch_game(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *));
int new_op(global_t *global, champion_t *tmp,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *));

int check_alive(global_t *global);
int print_in_hexa(global_t *global);
void change_cycle(global_t *global);
int start_game(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *));

void display_info(global_t *global);

void launch_game_graphical(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *));
#endif /* !SRC_H_ */
