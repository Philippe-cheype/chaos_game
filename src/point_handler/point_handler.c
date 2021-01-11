/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** get_point     - transforms char * to int and returns a sfVector2i
** random_point  - generates semi-random numbers according to screen x and y
** assign_random - assigns random values to points a, b and c
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/lib.h"
#include "../includes/my.h"

sfVector2i get_point(char *x, char *y)
{
    sfVector2i point;

    point.x = my_getnbr(x);
    point.y = my_getnbr(y);
    return (point);
}

static sfVector2i random_point(void)
{
    sfVector2i point;

    point.x = rand() % (WIDTH + 1);
    point.y = rand() % (HEIGHT + 1);
    return (point);
}

void assign_random(pos_t *pos)
{
    srand((unsigned int)time(NULL) * rand());
    pos->a = random_point();
    pos->b = random_point();
    pos->c = random_point();
}
