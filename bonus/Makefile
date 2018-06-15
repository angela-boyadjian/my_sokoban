##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile for projetcs
##

CC	=	gcc -Wall -Wextra -lncurses

RM	=	rm -rf

TEST_CC	=	gcc -Wall -Wextra -lncurses -I./include

CFLAGS	+=	-I./include

NAME	=	my_sokoban

SRCS	=	srcs/main.c \
		srcs/init.c \
		srcs/menu.c \
		srcs/error.c \
		srcs/defeate.c \
		srcs/check_map.c \
		srcs/display.c \
		srcs/get_nb_box.c \
		srcs/read_file.c \
		srcs/sokoban.c \
		srcs/check.c \
		srcs/end_game.c

SRCS_2	=	

SRCS_TESTS=	tests/test_get_path.c \

GCDA_FILES=     $(SRCS_2:.c=.gcda) $(SRCS_TESTS:.c=.gcda)

GCNO_FILES=     $(SRCS_2:.c=.gcno) $(SRCS_TESTS:.c=.gcno)

OBJ=		$(SRCS_2:.c=.o) $(SRCS_TESTS:.c=.o)

LDFLAGS=	-lcriterion --coverage -L./lib -lmy

TEST_NAME=	units

OBJS	=	$(SRCS:.c=.o)

LIB =		-L./lib -lmy

all:		$(NAME)

tests_run:	EXEC
		./$(TEST_NAME)

EXEC:		$(OBJ)
		$(TEST_CC) -o $(TEST_NAME) $(OBJ) $(LDFLAGS)

$(NAME):	$(OBJS)
		make -C ./lib/my
		$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
		$(RM) $(OBJS)
		$(RM) $(OBJ)
		$(RM) $(GCDA_FILES)
		$(RM) main.gcda
		$(RM) main.gcno
		$(RM) $(GCNO_FILES)
		make -C ./lib/my clean

fclean: 	clean
		$(RM) $(NAME)
		$(RM) $(TEST_NAME)
		$(RM) lib/*.a
		make -C ./lib/my fclean


re:		fclean all

.PHONY:		all exec tests_run clean fclean re