/*
** EPITECH PROJECT, 2021
** Lib My
** File description:
** My lib prototypes
*/

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
int my_putstr(char const *);
int my_put_nbr(int nb);
void my_put_tbl(const char **tbl);
int my_strlen(char const *str);
int my_getnbr(char const *str);

#ifndef LPRINTF_H_
#define LPRINTF_H_

int my_lprintf(char const *expr, ...);

#endif /* LPRINTF_H_ */

#endif /* MY_H_ */
