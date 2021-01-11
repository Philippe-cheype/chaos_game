/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** Gives the length of a string.
*/

int my_strlen(char const *str)
{
    int c;

    for (c = 0; str[c] != '\0'; c++);
    return (c);
}
