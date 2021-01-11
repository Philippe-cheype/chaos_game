/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** plot_points   - shows the main points defining the area and the first point
** draw_point    - chooses a point from the ones given / randomly generated and
**                 steps forwards drawing the next point
** assign_random - assigns random coordinates if none were given and defines
**                 the first points value.
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/lib.h"

void plot_points(framebuffer_t *fb, pos_t *pos, sfColor color)
{
    for (int i = 0; i < pos->pts_count; i++)
        my_draw_diamond(fb, pos->points[i], color);
    my_put_pixel(fb, pos->move, COLOR);
}

void draw_point(framebuffer_t *fb, pos_t *pos, sfColor color)
{
    int dice;

    dice = random_nth(pos->pts_count);
    pos->move.x = my_average(pos->move.x, pos->points[dice].x);
    pos->move.y = my_average(pos->move.y, pos->points[dice].y);
    my_put_pixel(fb, pos->move, COLOR);
}

void assign_random(pos_t *pos)
{
    srand((unsigned int)time(NULL) * rand());
    for (int i = 0; i < pos->pts_count; i++)
        pos->points[i] = random_point();
    pos->move.x = my_average(pos->points[0].x, pos->points[1].x);
    pos->move.y = my_average(pos->points[0].y, pos->points[1].y);
}
