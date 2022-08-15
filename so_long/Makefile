# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:39:12 by ccantale          #+#    #+#              #
#    Updated: 2022/08/15 02:00:51 by ccantale         ###   ########.fr        #
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
		  		get_xpm.c \
		  		move.c \
				check_for_coll.c \
				animation.c \
				step.c

LIBFT		= 	libft/libft.a
MINI		= 	minilibX/libmlx.dylib

OBJ			= 	$(FILES:.c=.o)


all: $(LIBFT) $(MINI) $(NAME)

$(MINI): 
	make -C minilibX

$(LIBFT):
	make -C libft
	make clean -C libft 

$(NAME): $(OBJ)
	$(CC) -g $(OBJ) -o $(NAME) -lmlx -framework openGL -framework AppKit $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $(FILES)

go: $(LIBFT) $(MINI) $(NAME)
	./$(NAME) test_map.ber

clean: 
	rm $(OBJ)

fclean:
	rm so_long

re: fclean
	make

norminette:
	norminette $(FILES) so_long.h

.PHONY: all clean fclean re norminette

