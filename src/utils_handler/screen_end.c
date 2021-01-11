/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** screen_end - free and destroy everything
** Debuggers will show you more or less 15Mb of data lost on exit
** that's CSFML's doing :) Thank you CSFML!
*/

#include <stdlib.h>
#include "../includes/lib.h"

void screen_end(framebuffer_t *fb, vars_t *va, pos_t *pos)
{
    free(pos);
    free(fb->pixels);
    free(fb);
    sfSprite_destroy(va->sprite);
    sfTexture_destroy(va->texture);
    sfRenderWindow_destroy(va->window);
    free(va);
}
