##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile library
##

SRC = 	./lib/my/my_printf.c	\
		./lib/my/change_base.c \
		./lib/my/flag_list.c \
		./lib/my/flag_list2.c \
		./lib/my/my_count_nbr.c \
		./lib/my/my_pointer_adress.c \
		./lib/my/my_put_nbr.c \
		./lib/my/my_put_unsign_nbr.c \
		./lib/my/my_putchar.c \
		./lib/my/my_putstr.c \
		./lib/my/my_revstr.c \
		./lib/my/my_str_count_len.c \
		./lib/my/my_strcpy.c \

OBJ = 	$(SRC:.c=.o)

NAME =	 libmy.a

all: 	$(NAME)
	rm ./lib/my/*.o
	cp ./lib/my/include/*.h ./

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ./../

clean:
	rm -f ./lib/my/$(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.h

re:	fclean all
