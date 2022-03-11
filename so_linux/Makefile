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

CC		= gcc
FLAGS		= -Wall -Wextra -Werror

NAME		= so_long

FILES		= so_long.c ft_check_map.c \
		  quit.c error.c \
		  loop.c get_xml.c

LIBFT		= libft/libft.a
MINI		= minilinuX/libmlx.a

OBJ		= $(FILES:.c=.o)


all: $(LIBFT) $(MINI) $(NAME)

$(MINI): minilinuX/
	make -C minilinuX

$(LIBFT): libft/
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Llibft -lft -LminilinuX -lmlx -L/usr/lib -IminilinuX -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -g -I/usr/include -IminilinuX -O3 -c $(FILES)

clean: 
	make clean -C minilinuX
	rm $(OBJ)

fclean: clean
	rm so_long

re: fclean
	make

.PHONY: all clean fclean re

