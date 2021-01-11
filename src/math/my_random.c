/*
** EPITECH PROJECT, 2021
** chaos_game (Workspace)
** File description:
** my_random
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/lib.h"

sfVector2i random_point(void)
{
    sfVector2i point;

    point.x = rand() % (WIDTH - 1) + 2;
    point.y = rand() % (HEIGHT - 1) + 2;
    return (point);
}

int random_nth(int n)
{
    int res;

    res = rand() % n;
    return (res);
}
