/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** Prints a char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
