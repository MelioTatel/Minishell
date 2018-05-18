##
## EPITECH PROJECT, 2017
## makefile
## File description:
## compile everything
##

SRC	=	src/cmd.c		\
		src/my_putstr.c		\
		src/my_strcpy.c		\
		src/my_strcmp.c		\
		src/my_strlen.c		\
		src/my_puttab.c		\
		src/path.c 		\
		src/binary.c		\
		src/exec_command.c	\
		src/my_str_to_wordtab.c	\
		src/count_words.c	\
		src/last_cd.c		\
		src/get_next_line.c	\
		src/my_getnbr.c		\
		src/clear_string.c	\
		src/my_strcat.c		\
		src/set_in.c		\
		src/detect_cmd.c	\
		src/put_in_list.c	\
		src/my_tabdup.c		\
		src/main.c

INC	=	-I./

CFLAGS	=	-g $(INC)
OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:		$(OBJ)
	gcc -o $(NAME) $(OBJ) $(INC) -lm 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
