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

SRC		=	src/main.c							\
			src/utils_handler/utils_create.c	\
			src/utils_handler/screen_end.c		\
			src/point_handler/my_put_pixel.c	\
			src/point_handler/plot_points.c		\
			src/point_handler/point_handler.c	\
			src/point_handler/get_new_points.c	\

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-L./lib/ -lmy -I./include/

LFLAGS	+=	-lcsfml-graphics -lcsfml-system

DFLAGS	+=	-W -Wall -Wextra -g3

all:		$(NAME)

$(NAME):	$(OBJ)
			make all    -C ./lib/
			$(CP) src/includes/*.h includes/
			$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LFLAGS) $(DFLAGS)

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
