# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 19:14:21 by ccantale          #+#    #+#              #
#    Updated: 2022/08/15 14:31:12 by ccantale         ###   ########.fr        #
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
	$(CC) $(FLAGS) -c $(FILES)

clean:
	rm $(OBJ)

fclean:
	rm $(NAME)

re: $(NAME) fclean
	rm *.o
	make

.PHONY: all clean fclean re
