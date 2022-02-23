# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:39:12 by ccantale          #+#    #+#              #
#    Updated: 2022/02/23 18:16:22 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
FLAGS		= -Wall -Wextra -Werror

NAME		= so_long
FILES		= so_long.c ft_check_map.c
LIBFT		= libft/libft.a
MINI		= minilibX/libmlx.dylib

OBJ			= $(FILES:.c=.o)


all: $(LIBFT) $(MINI) $(NAME)

$(MINI): minilibX/
	make -C minilibX

$(LIBFT): libft/
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MINI) -o so_long

%.o: %.c
	$(CC) $(FLAGS) -c $(FILES)

clean: all
	make clean -C minilibX
	make clean -C libft
	rm -r obj
	rm so_long.o

fclean: clean
	make fclean -C libft
	rm so_long

re: fclean
	make

.PHONY: all clean fclean re

