# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:39:12 by ccantale          #+#    #+#              #
#    Updated: 2022/02/23 16:40:28 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
FLAGS		= -Wall -Wextra -Werror

NAME		= so_long
FILES		= so_long.c ft_check_map.c

OBJ			= $(patsubst .%, obj%, $(FILES:.c=.o))


all: libmlx.dylib libftprintf.a obj $(NAME)

libmlx.dylib:
	make -C minilibX

libftprintf.a: printf/
	make -C printf

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o so_long

obj:
	mkdir obj

obj/%.o: %.c
	$(CC) $(FLAGS) -c $(FILES)

clean: all
	make clean -C minilibX
	make clean -C printf
	rm -r obj

fclean: clean
	make fclean -C printf
	rm so_long

.PHONY: all clean fclean  

