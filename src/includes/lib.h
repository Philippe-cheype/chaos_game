/*
** EPITECH PROJECT, 2021
** chaos_game
** File description:
** Utils lib prototypes / macros / structures used.
*/

#ifndef LIB_H_
#define LIB_H_

#include <SFML/Graphics.h>

#ifndef MACROS_H_
#define MACROS_H_

#ifndef ERROR_H_
#define ERROR_H_

#include <unistd.h>

#define BAD_PARAMS       write(2, "Error: Wrong parameters, "     \
                                "run with -h for more details:\n" \
                                "      ./chaos_game -h\n", 78);

#define ERROR_CODE       84
#define ERROR_CODE_NULL  NULL
#define SUCCESS_CODE     0
#define INFO_CODE        1

#endif /* ERROR_H_ */

#define HEIGHT           1080
#define WIDTH            1920
#define PIXELS           32
#define FPS              25

#define COLOR            sfWhite
#define DEPTH_MAX        1000000

#endif /* MACROS_H_ */

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct vars_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
} vars_t;

typedef struct pos_s {
    sfVector2i *points;
    sfVector2i move;
    int pts_count;
    int steps;
} pos_t;

void screen_end(framebuffer_t *fb, vars_t *va, pos_t *pos);
void framebuffer_clear(framebuffer_t *fb, sfColor color);
framebuffer_t *framebuffer_create(void);
vars_t *vars_create(framebuffer_t *fb);
pos_t *pos_create(char *points_count);

void plot_points(framebuffer_t *fb, pos_t *pos, sfColor color);
void draw_point(framebuffer_t *fb, pos_t *pos, sfColor color);
sfVector2i get_point(char *x, char *y);
void assign_random(pos_t *pos);

void my_draw_diamond(framebuffer_t *fb, sfVector2i point, sfColor color);
void my_put_pixel(framebuffer_t *fb, sfVector2i point, sfColor color);

sfVector2i random_point(void);
int my_average(int a, int b);
int random_nth(int n);

#endif /* LIB_H_ */
