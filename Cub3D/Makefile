# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 17:01:39 by ccantale          #+#    #+#              #
#    Updated: 2023/02/15 18:13:56 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc
FLAGS		=		-Wall -Wextra -Werror -g

NAME		=		cub3D

SRC			=		main.c string_utils.c \
					error_msg.c check_map.c \
					cub_calloc.c

OBJ			=		$(SRC:.c=.o)



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	rm $(OBJ)

fclean:
	rm $(NAME)

kill: clean fclean

re: kill
	make

.PHONY: all clean fclean kill re
