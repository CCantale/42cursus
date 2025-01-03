####################################
############# Makefile #############
####################################

NAME		=		Colleen

CC		=		gcc
FLAGS		=		-Wall -Wextra -Werror

SRCS		=		Colleen.c
OBJS		=		$(SRCS:.c=.o)

TEST_FILE	=		test



all: $(NAME)


$(NAME): $(OBJS)
	@$(CC) $^ -o $(NAME)
	@make clean
	@echo Colleen compiled successfully!

%.o: %.c
	@$(CC) $(FLAGS) -c $^

clean:
	@rm *.o

fclean:
	@rm $(NAME)

re: fclean
	@make

test:
	@./$(NAME) > $(TEST_FILE); diff $(SRCS) $(TEST_FILE); rm $(TEST_FILE)

.PHONY: all clean fclean re
