/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** random_point - chooses a random point inside the game box
** random_nth   - given n it will randomly generate an int from 0 - n
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
    return (rand() % n);
}
