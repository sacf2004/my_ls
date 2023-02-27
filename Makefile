##
## EPITECH PROJECT, 2023
## My_ls
## File description:
## Ls
##

SRC	=	./functions_ls.c \
		./my_strcat.c \
		./my_strcmp.c \
		./my_ls_l.c \
		./flags.c \
		./specifc_nb_of_length.c \
		./ls_with_path.c \
		./my_ls_r_may.c \
		./my_ls_r_may_with_path.c \
		./my_ls_l_with_path.c \
		./my_ls_r_help.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME)
	rm ./*.o
	rm ./libmy.a

$(NAME):	$(OBJ)
	make -C printf
	gcc -Wall -Werror -o $(NAME) $(OBJ) libmy.a

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
