/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** my_draw_diamond - draws a diamond shape given coords and a color.
** Reference:
**   X
**  XXX
** XXXXX
**  XXX
**   X
*/

#include "../includes/lib.h"

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
