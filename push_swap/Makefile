# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 16:24:46 by ccantale          #+#    #+#              #
#    Updated: 2022/04/11 18:35:03 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		gcc
FLAGS	=		-Wall -Wextra -Werror

NAME	=		push_swap

FILES	=		main.c \
				get_swap.c \
				ft_atoi.c

OBJ		=		$(FILES:.c=.o)



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $(FILES)

clean:
	rm *.o

fclean:
	rm $(NAME)

re: clean
	make

.PHONY: all clean fclean re
