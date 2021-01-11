/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** plot_points - renders the a, b, c points on screen
*/

#include "../includes/lib.h"

void plot_points(framebuffer_t *fb, pos_t *pos, sfColor color)
{
    my_put_pixel(fb, pos->a, color);
    my_put_pixel(fb, pos->b, color);
    my_put_pixel(fb, pos->c, color);
}
