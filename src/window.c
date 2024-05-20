/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-leandre.ramos
** File description:
** window.c
*/

#include "../include/src.h"

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
    sfText_setPosition(text, (sfVector2f){10, 10});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    // free(cycle);
}

int print_in_hexa(global_t *global)
{
    print_cycle(global);
    char hex[3];
    sfFont *font = sfFont_createFromFile("bonus/robotmono.ttf");
    sfText *text = sfText_create();
    sfColor colors[] = {sfWhite, sfRed, sfGreen, sfBlue, sfYellow, sfMagenta};
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 10);


    int columns = 127;
    float startX = 10;
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
    print_in_hexa(global);
    sfRenderWindow_display(global->window);
}
