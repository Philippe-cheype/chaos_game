/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** my_put_pixel - puts a pixel
** my_draw_diamond - draws a diamond around a point
** plot_points  - renders the a, b, c points on screen
*/

#include "../includes/lib.h"

void my_put_pixel(framebuffer_t *fb, sfVector2i point, sfColor color)
{
    int n;

    n = ((fb->width * point.y * 4) + (point.x * 4));
    fb->pixels[n] = color.r;
    fb->pixels[n + 1] = color.g;
    fb->pixels[n + 2] = color.b;
    fb->pixels[n + 3] = color.a;
}

void my_draw_diamond(framebuffer_t *fb, sfVector2i point, sfColor color)
{
    sfVector2i temp_point;

    for (int i = point.x - 1; i < point.x + 2; i++)
        for (int j = point.y - 1; j < point.y + 2; j++) {
            temp_point.x = i;
            temp_point.y = j;
            my_put_pixel(fb, temp_point, color);
        }
    for (int i = point.x - 2; i < point.x + 3; i += 4) {
        temp_point.x = i;
        temp_point.y = point.y;
        my_put_pixel(fb, temp_point, color);
    }
    for (int j = point.y - 2; j < point.y + 3; j += 4) {
        temp_point.x = point.x;
        temp_point.y = j;
        my_put_pixel(fb, temp_point, color);
    }
}

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
