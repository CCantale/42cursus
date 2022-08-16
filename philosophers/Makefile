# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 19:14:21 by ccantale          #+#    #+#              #
#    Updated: 2022/08/16 16:14:50 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		gcc
FLAGS	=		-Wall -Wextra -Werror

NAME	=		philo

FILES	=		main.c \
				messages.c \
				inform.c \
				utilitarianism.c \
				debug.c

OBJ		=		$(FILES:.c=.o)



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -g -c $(FILES)

clean:
	rm $(OBJ)

fclean:
	rm $(NAME)

re: $(NAME) fclean
	rm *.o
	make

go:
	make
	./philo 2 2 2 2

l:
	make
	leaks --atExit -- ./philo 2 2 2 2

.PHONY: all clean fclean re go l
