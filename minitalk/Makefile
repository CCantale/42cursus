# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 16:42:55 by ccantale          #+#    #+#              #
#    Updated: 2022/08/12 00:49:38 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc
FLAGS		=		-Wall -Wextra -Werror

NAME		=		server
NAME2		=		client

FILES		=		server.c client.c
OBJ			=		$(FILES:.c=.o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(NAME).o -o $@ libft/libft.a

$(NAME2): $(OBJ)
	$(CC) $(FLAGS) $(NAME2).o -o $@ libft/libft.a

%.o: %.c
	$(CC) $(FLAGS) -c $(FILES)

clean:
	rm *.o

fclean:
	rm server
	rm client

re: fclean
	make

.PHONY: all clean fclean re
