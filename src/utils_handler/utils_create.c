/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** framebuffer_create - create the framebuffer
** vars_create        - creates the used variables for graphics
** pos_create         - creates and assigns values to n points
*/

#include <stdlib.h>
#include "../includes/lib.h"
#include "../includes/my.h"

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

pos_t *pos_create(char *points_count)
{
    pos_t *pos;

    pos = malloc(sizeof(*pos));
    if (!pos) return (ERROR_CODE_NULL);
    if ((pos->pts_count = my_getnbr(points_count)) < 3) {
        free(pos);
        return (ERROR_CODE_NULL);
    }
    pos->points = malloc(sizeof(sfVector2i) * pos->pts_count);
    if (!pos->points) {
        free(pos);
        return (ERROR_CODE_NULL);
    }
    pos->steps = 0;
    assign_random(pos);
    return (pos);
}
