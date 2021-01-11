##
## EPITECH PROJECT, 2021
## chaos_game
## File description:
## Makefile
##

NAME	=	chaos_game

CC		=	gcc

RM		=	rm -f

CP		=	cp -f

SRC		=	src/main.c								\
			src/drawing/my_put_pixel.c				\
			src/drawing/my_draw_diamond.c			\
			src/math/my_average.c					\
			src/math/my_random.c					\
			src/point_handler/get_point.c			\
			src/point_handler/show_points.c			\
			src/utils_handler/framebuffer_clear.c	\
			src/utils_handler/screen_end.c			\
			src/utils_handler/utils_create.c		\

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-L./lib/ -lmy -I./include/

LFLAGS	+=	-lcsfml-graphics -lcsfml-system -lm

all:		$(NAME)

$(NAME):	$(OBJ)
			make all    -C ./lib/
			$(CP) src/includes/*.h includes/
			$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LFLAGS)

clean:
			$(RM) $(OBJ)
			make clean  -C ./lib/

fclean:		clean
			$(RM) $(NAME)
			$(RM) includes/*.h
			make fclean -C ./lib/

re:			fclean all
			make re     -C ./lib/

.PHONY:		all clean fclean re
