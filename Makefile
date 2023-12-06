##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## it makes files
##

.PHONY: all val clean fclean re

CFLAGS  += -W -Wall -Wextra -Wundef -O2 -g
LDFLAGS = -L./lib/my -lmy

SRC		=	$(wildcard src/*.c)

OBJ		=	$(SRC:.c=.o)

NAME = my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		make clean -C ./lib/my
		rm -f $(OBJ)

fclean:                 clean
		make fclean -C ./lib/my
		rm -f $(NAME)

re:		fclean all
