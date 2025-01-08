####################################
############# Makefile #############
####################################

NAME		=		Sully

CC		=		gcc
FLAGS		=		-Wall -Wextra -Werror

SRCS		=		Sully.c
OBJS		=		$(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJS)
	@$(CC) $^ -o $(NAME)
	@make clean
	@echo SUlly compiled successfully!

%.o: %.c
	@$(CC) $(FLAGS) -c $^

clean:
	@rm *.o

fclean:
	@rm Sully_*
	@rm $(NAME)

re: fclean
	@make

test: $(NAME)
	@./$(NAME)

.PHONY: all clean fclean re
