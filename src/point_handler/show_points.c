/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** my_put_pixel - puts a pixel
** my_draw_diamond - draws a diamond around a point
** plot_points  - renders the a, b, c points on screen
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/lib.h"

void plot_points(framebuffer_t *fb, pos_t *pos, sfColor color)
{
    my_draw_diamond(fb, pos->a, color);
    my_draw_diamond(fb, pos->b, color);
    my_draw_diamond(fb, pos->c, color);
    my_put_pixel(fb, pos->move, COLOR);
}

void draw_point(framebuffer_t *fb, pos_t *pos, sfColor color, int sides)
{
    int dice;

    dice = random_nth(sides);
    if (dice == 0) {
        pos->move.x = my_average(pos->move.x, pos->a.x);
        pos->move.y = my_average(pos->move.y, pos->a.y);
    } else if (dice == 1) {
        pos->move.x = my_average(pos->move.x, pos->b.x);
        pos->move.y = my_average(pos->move.y, pos->b.y);
    } else {
        pos->move.x = my_average (pos->move.x, pos->c.x);
        pos->move.y = my_average(pos->move.y, pos->c.y);
    }
    my_put_pixel(fb, pos->move, COLOR);
}

void assign_random(pos_t *pos)
{
    srand((unsigned int)time(NULL) * rand());
    pos->a = random_point();
    pos->b = random_point();
    pos->c = random_point();
    pos->move.x = my_average(pos->a.x, pos->b.x);
    pos->move.y = my_average(pos->a.y, pos->b.y);
}
