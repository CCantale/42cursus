####################################
############# Makefile #############
####################################

NAME		=		Sully

CC		=		gcc
FLAGS		=		-Wall -Wextra -Werror

SRCS		=		Sully.c


all: $(NAME)


$(NAME): $(SRCS)
	@$(CC) $(FLAGS) $^ -o $(NAME)
	@echo Sully compiled successfully!

clean:
	@rm Sully_*
	@rm $(NAME)

re: clean
	@make

test: $(NAME)
	@./$(NAME)

.PHONY: all clean fclean re
