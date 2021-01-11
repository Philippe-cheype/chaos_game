/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** Prints a char ** in a casual method
** every char * will be printed in a line with a EOL.
** remove line 20 if your char ** already contains EOL's.
*/

#include <stdio.h>

void my_putchar(char);

int my_putstr(char const *);

void my_put_tbl(const char **tbl)
{
    for (int i = 0; tbl[i]; i++) {
        my_putstr(tbl[i]);
        my_putchar('\n');
    }
    return;
}
