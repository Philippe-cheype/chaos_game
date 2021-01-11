/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** my_put_pixel - puts a single pixel to screen given coordinates and a color
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
