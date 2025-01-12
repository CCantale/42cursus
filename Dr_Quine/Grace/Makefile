####################################
############# Makefile #############
####################################

NAME		=		Grace

CC		=		gcc
FLAGS		=		-Wall -Wextra -Werror

SRCS		=		Grace.c
OBJS		=		$(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJS)
	@$(CC) $^ -o $(NAME)
	@make clean
	@echo Grace compiled successfully!

%.o: %.c
	@$(CC) $(FLAGS) -c $^

clean:
	@rm *.o

fclean:
	@rm Grace_kid.c
	@rm $(NAME)

re: fclean
	@make

test: $(NAME)
	@./$(NAME)
	diff Grace.c Grace_kid.c

.PHONY: all clean fclean re
