# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 17:01:39 by ccantale          #+#    #+#              #
#    Updated: 2023/02/23 15:35:42 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc
FLAGS		=		-Wall -Wextra -Werror -g

NAME		=		cub3D

SRC			=		main.c \
					error/error_msg.c error/error_null.c \
					map_checks/check_map.c \
					utils/cub_calloc.c utils/cub_join.c \
					utils/cub_split.c utils/cub_strdup.c \
					utils/cub_strlen.c utils/cub_strncpy.c \
					utils/cub_substr.c \
					cantalloc/cantalloc.c cantalloc/cantalloc_dup.c \
					static_handlers/static_handlers_init.c \
					static_handlers/map_handler.c \
					static_handlers/texture_handler.c \
					static_handlers/get_texture.c

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
