/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** help_menu      - renders the help menu when given "-h"
** param_handling - handles special params given such as "-h"
** event_handler  - handles events found in the main loop
** main_loop      - main loop function
** main           - main function
*/

#include "includes/lib.h"
#include "includes/my.h"

static void help_menu(void)
{
    my_putstr("USAGE\n");
    my_putstr("    Usage: ./chaos_game [OPTIONS] [XA YA XB YB XC YC]\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    -h            this help message\n");
    my_putstr("    XA, XB, XC    value from 5 to 1915 (Screen width)\n");
    my_putstr("    YA, YB, YC    value from 5 to 1075 (Screen height)\n");
    my_putstr("KEYS\n");
    my_putstr("    R             Reset\n");
}

static int param_handling(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help_menu();
        return (INFO_CODE);
    }
    return (SUCCESS_CODE);
}

static void event_handler(framebuffer_t *fb, vars_t *va, pos_t *pos)
{
    if (va->event.type == sfEvtClosed)
        sfRenderWindow_close(va->window);
    if (va->event.type == sfEvtKeyPressed)
        if (va->event.key.code == sfKeyR) {
            assign_random(pos);
            framebuffer_clear(fb, sfBlack);
            pos->steps = 0;
            plot_points(fb, pos, sfRed);
        }
}

static void main_loop(framebuffer_t *fb, vars_t *va, pos_t *pos)
{
    plot_points(fb, pos, sfRed);
    while (sfRenderWindow_isOpen(va->window)) {
        while (sfRenderWindow_pollEvent(va->window, &va->event))
            event_handler(fb, va, pos);
        while (pos->steps <= DEPTH_MAX) {
            draw_point(fb, pos, COLOR);
            pos->steps++;
        }
        sfTexture_updateFromPixels(va->texture, fb->pixels,    \
                                    fb->width, fb->height, 0, 0);
        sfRenderWindow_drawSprite(va->window, va->sprite, NULL);
        sfRenderWindow_display(va->window);
    }
}

int main(int ac, char **av)
{
    framebuffer_t *fb;
    vars_t *va;
    pos_t *pos;

    if (ac != 2) {
        BAD_PARAMS;
        return (ERROR_CODE);
    }
    if (param_handling(av) == INFO_CODE) return (SUCCESS_CODE);
    if ((fb = framebuffer_create())   == ERROR_CODE_NULL) return (ERROR_CODE);
    if ((va = vars_create(fb))        == ERROR_CODE_NULL) return (ERROR_CODE);
    if ((pos = pos_create(av[1]))     == ERROR_CODE_NULL) return (ERROR_CODE);
    sfSprite_setTexture(va->sprite, va->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(va->window, FPS);
    main_loop(fb, va, pos);
    screen_end(fb, va, pos);
    return (0);
}
