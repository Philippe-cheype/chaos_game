/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** framebuffer_create - create the framebuffer
** vars_create        - creates the used variables for graphics
** pos_create         - creates and assigns values to the points a, b, c
*/

#include <stdlib.h>
#include "../includes/lib.h"

framebuffer_t *framebuffer_create(void)
{
    framebuffer_t *fb;

    fb = malloc(sizeof(*fb));
    if (!fb) return (ERROR_CODE_NULL);
    fb->width = WIDTH;
    fb->height = HEIGHT;
    fb->pixels = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));
    if (!fb->pixels) {
        free(fb);
        return (ERROR_CODE_NULL);
    }
    return (fb);
}

vars_t *vars_create(framebuffer_t *fb)
{
    vars_t *va;

    va = malloc(sizeof(*va));
    if (!va) return (NULL);
    va->mode.width = fb->width;
    va->mode.height = fb->height;
    va->mode.bitsPerPixel = PIXELS;
    va->window = sfRenderWindow_create(va->mode, "My Radar", sfClose, NULL);
    va->texture = sfTexture_create(fb->width, fb->height);
    va->sprite = sfSprite_create();
    sfSprite_setTexture(va->sprite, va->texture, sfFalse);
    return (va);
}

pos_t *pos_create(int ac, char **av)
{
    pos_t *pos;

    pos = malloc(sizeof(*pos));
    pos->depth = 0;
    if (ac == 7) {
        pos->a = get_point(av[1], av[2]);
        pos->b = get_point(av[3], av[4]);
        pos->c = get_point(av[5], av[6]);
    } else
        assign_random(pos);
    pos->move.x = my_average(pos->a.x, pos->b.x);
    pos->move.y = my_average(pos->a.y, pos->b.y);
    return (pos);
}
