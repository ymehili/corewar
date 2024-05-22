/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** window.c
*/

#include "../include/src.h"

static void print_register(champion_t *champion, global_t *global, float base_x, float base_y)
{
    sfFont *font = sfFont_createFromFile("bonus/robotmono.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 15);
    sfText_setFillColor(text, sfWhite);
    char reg[100];

    for (int i = 0; i < REG_NUMBER; i++) {
        sprintf(reg, "r%d: %d", i + 1, champion->reg[i]);
        sfText_setString(text, reg);
        sfText_setPosition(text, (sfVector2f){base_x, base_y + (i * 20)}); // Reduced spacing between lines
        sfRenderWindow_drawText(global->window, text, NULL);
    }
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void print_process_count(champion_t *champion, global_t *global, float base_x, float base_y)
{
    sfFont *font = sfFont_createFromFile("bonus/robotmono.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 17);
    sfText_setFillColor(text, sfWhite);
    char process_count[100];
    
    int count = 1;
    champion_t *process = champion->clone_next;
    if (process != NULL)
        count = 0;
    while (process != NULL) {
        count++;
        process = process->next;
    }
    
    sprintf(process_count, "Nb processes: %d", count);
    sfText_setString(text, process_count);
    sfText_setPosition(text, (sfVector2f){base_x, base_y});
    sfRenderWindow_drawText(global->window, text, NULL);
    
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void print_lives_count(champion_t *champion, global_t *global, float base_x, float base_y)
{
    sfFont *font = sfFont_createFromFile("bonus/robotmono.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 17);
    sfText_setFillColor(text, sfWhite);
    char lives_count[100];
    
    sprintf(lives_count, "lives: %d", champion->nb_live);
    sfText_setString(text, lives_count);
    sfText_setPosition(text, (sfVector2f){base_x, base_y});
    sfRenderWindow_drawText(global->window, text, NULL);
    
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void print_champ_pc(champion_t *champion, global_t *global, float base_x, float base_y)
{
    sfFont *font = sfFont_createFromFile("bonus/robotmono.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 17);
    sfText_setFillColor(text, sfWhite);
    char champ_pc[100];
    
    sprintf(champ_pc, "Champ PC: %d", champion->pc);
    sfText_setString(text, champ_pc);
    sfText_setPosition(text, (sfVector2f){base_x, base_y});
    sfRenderWindow_drawText(global->window, text, NULL);
    
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void print_champ_carry(champion_t *champion, global_t *global, float base_x, float base_y)
{
    sfFont *font = sfFont_createFromFile("bonus/robotmono.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 17);
    sfText_setFillColor(text, sfWhite);
    char champ_carry[100];
    
    sprintf(champ_carry, "Carry: %d", champion->carry);
    sfText_setString(text, champ_carry);
    sfText_setPosition(text, (sfVector2f){base_x, base_y});
    sfRenderWindow_drawText(global->window, text, NULL);
    
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void print_info_champion(global_t *global)
{
    sfFont *font = sfFont_createFromFile("bonus/robotmono.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setFillColor(text, sfWhite);
    char info[100];
    float base_x = 10;
    float base_y = 40;
    float x_offset = 300;
    float y_offset = 30;
    float process_y_offset = 17;

    for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
        sprintf(info, "Champion %d: %s", tmp->id, tmp->name);
        sfText_setString(text, info);
        sfText_setPosition(text, (sfVector2f){base_x, base_y});
        sfRenderWindow_drawText(global->window, text, NULL);

        print_register(tmp, global, base_x, base_y + y_offset);
        print_lives_count(tmp, global, base_x, base_y + y_offset + (REG_NUMBER * 20));
        print_process_count(tmp, global, base_x, base_y + y_offset + (REG_NUMBER * 20) + process_y_offset);
        print_champ_pc(tmp, global, base_x, base_y + y_offset + (REG_NUMBER * 20) + process_y_offset + 17);
        print_champ_carry(tmp, global, base_x, base_y + y_offset + (REG_NUMBER * 20) + process_y_offset + 34);
        base_x += x_offset;
    }
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void print_cycle(global_t *global)
{
    sfFont *font = sfFont_createFromFile("bonus/robotmono.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setFillColor(text, sfWhite);
    char cycle[100];

    sprintf(cycle, "Cycle: %d", global->cycle);
    sfText_setString(text, cycle);
    sfText_setPosition(text, (sfVector2f){10, 480});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

int print_in_window(global_t *global)
{
    print_cycle(global);
    print_info_champion(global);
    char hex[3];
    sfFont *font = sfFont_createFromFile("bonus/robotmono.ttf");
    sfText *text = sfText_create();
    sfColor colors[] = {sfWhite, sfRed, sfGreen, sfBlue, sfYellow, sfMagenta};
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 10);

    int columns = 128;
    float startX = 0;
    float startY = 510;
    float cellWidth = 15;
    float cellHeight = 10;
    sfRectangleShape *highlight = sfRectangleShape_create();
    sfRectangleShape_setSize(highlight, (sfVector2f){cellWidth, cellHeight});
    sfRectangleShape_setFillColor(highlight, sfWhite);

    for (int i = 0; i < MEM_SIZE; i++) {
        hex[0] = "0123456789ABCDEF"[((unsigned char)global->map[i]) / 16];
        hex[1] = "0123456789ABCDEF"[((unsigned char)global->map[i]) % 16];
        hex[2] = '\0';
        int color_index = global->colors_map[i];
        if (color_index > 0 && color_index < sizeof(colors) / sizeof(colors[0]))
            sfText_setFillColor(text, colors[color_index]);
        else
            sfText_setFillColor(text, sfWhite);
        for (champion_t *tmp = global->champions; tmp != NULL; tmp = tmp->next) {
            for (champion_t *tmp2 = tmp; tmp2 != NULL; tmp2 = tmp2->clone_next)
                if (i == tmp2->pc) {
                    sfRectangleShape_setPosition(highlight, (sfVector2f){startX + (i % columns) * cellWidth, startY + (i / columns) * cellHeight});
                    sfRenderWindow_drawRectangleShape(global->window, highlight, NULL);
                    break;
                }
        }
        sfText_setString(text, hex);

        float x = startX + (i % columns) * cellWidth;
        float y = startY + (i / columns) * cellHeight;
        sfText_setPosition(text, (sfVector2f){x, y});

        sfRenderWindow_drawText(global->window, text, NULL);
    }

    sfText_destroy(text);
    sfFont_destroy(font);

    return -2;
}

void display_info(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    print_in_window(global);
    sfRenderWindow_display(global->window);
}

/**
 * @brief           Launches the game loop.
 *
 * @param global    The global structure containing game data.
 * @param all_command   An array of function pointers to the commands.
 */
void launch_game_graphical(global_t *global,
    int (*all_command[NB_COMMAND])(global_t *, champion_t *, pc_t *))
{
    int check_live = 0;
    int end = 0;
    int paused = 0;
    sfEvent event;
    sfVideoMode mode = {1920, 1080, 32};
    global->window = sfRenderWindow_create(mode, "Corewar", sfResize | sfClose, NULL);

    while (sfRenderWindow_isOpen(global->window) && global->nb_champion != 1) {
        while (sfRenderWindow_pollEvent(global->window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
                sfRenderWindow_close(global->window);
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
                paused = !paused;
            }
        }

        if (!paused) {
            if (check_live >= global->cycle_to_die && global->cycle_to_die > 0) {
                check_live = 0;
                end = check_alive(global);
            }
            if (end == 1)
                return;
            if (global->live_count >= NBR_LIVE)
                change_cycle(global);
            check_live++;
            if (start_game(global, all_command) == -2)
                return;
        }

        display_info(global);
    }
    sfRenderWindow_destroy(global->window);
}
