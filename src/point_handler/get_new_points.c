/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** my_average    - return the average of two ints
** get_new_point - returns the new values for the a, b, c points
*/

#include "../includes/lib.h"

int my_average(int a, int b)
{
    return ((a + b) / 2);
}

void get_new_points(pos_t *pos)
{
    pos->a.x = my_average(pos->a.x, pos->b.x);
    pos->a.y = my_average(pos->a.y, pos->b.y);
    pos->b.x = my_average(pos->b.x, pos->c.x);
    pos->b.y = my_average(pos->b.y, pos->c.y);
    pos->c.x = my_average(pos->c.x, pos->a.x);
    pos->c.y = my_average(pos->c.y, pos->a.y);
}
