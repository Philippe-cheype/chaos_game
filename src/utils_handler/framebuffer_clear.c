/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** framebuffer_clear - fills the entire screen with a specified color
*/

#include "../includes/lib.h"

void framebuffer_clear(framebuffer_t *fb, sfColor color)
{
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            sfVector2i point = {i, j};
            my_put_pixel(fb, point, color);
        }
    }
}
