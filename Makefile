##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## screensaver makefile
##

SRC	=	$(SRC_DIR)main.c	\
		$(SRC_DIR)launch_minishell.c	\
		$(SRC_DIR)error.c	\
		$(SRC_DIR)copy_tab.c	\
		$(SRC_DIR)my_getenv.c	\
		$(SRC_DIR)fetch_function.c	\
		$(SRC_DIR)is_builtin.c	\
		$(SRC_DIR)is_binary.c	\
		$(SRC_DIR)choose_prompt.c	\
		$(SRC_DIR)init_input.c	\
		$(SRC_DIR)$(BUILTINS_DIR)my_cd.c	\
		$(SRC_DIR)$(BUILTINS_DIR)my_setenv.c	\
		$(SRC_DIR)$(BUILTINS_DIR)my_unsetenv.c	\
		$(SRC_DIR)$(BUILTINS_DIR)my_env.c	\
		$(SRC_DIR)$(BUILTINS_DIR)my_exit.c	\

SRC_DIR = src/

BUILTINS_DIR	=	builtins/

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-Iinclude

LDFLAGS	=	-Llib/my

LDLIBS	=	-lmy

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	make -C lib/my clean
	rm -f $(OBJ)

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
