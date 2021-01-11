/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** get_point - transforms char * to int and returns a sfVector2i
*/

#include "../includes/lib.h"
#include "../includes/my.h"

sfVector2i get_point(char *x, char *y)
{
    sfVector2i point;

    point.x = my_getnbr(x);
    point.y = my_getnbr(y);
    return (point);
}
