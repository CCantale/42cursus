# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:39:12 by ccantale          #+#    #+#              #
#    Updated: 2022/04/06 18:18:55 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

NAME		=	so_long

FILES		=	so_long.c \
				split_nl.c \
			 	ft_check_map.c \
		 		quit.c \
		  		error.c \
		  		loop.c \
		  		get_xml.c \
		  		move.c \
				check_for_coll.c

LIBFT		= 	libft/libft.a
MINI		= 	minilibX/libmlx.a

OBJ			= 	$(FILES:.c=.o)


all: $(LIBFT) $(MINI) $(NAME)

$(MINI): minilibX/
	make -C minilibX

$(LIBFT): libft/
	make -C libft
	make clean -C minilibX

$(NAME): $(OBJ)
	$(CC) -g $(OBJ) -o $(NAME) -lmlx -framework openGL -framework AppKit $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $(FILES)

clean: 
	make clean -C minilibX
	rm $(OBJ)

fclean:
	rm so_long

re: fclean
	make

.PHONY: all clean fclean re

