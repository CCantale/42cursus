# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 16:42:55 by ccantale          #+#    #+#              #
#    Updated: 2022/08/10 16:53:47 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc
FLAGS		=		-Wall -Wextra -Werror

NAME		=		server
NAME2		=		client

SERVER		=		server.c
O_SERVER	=		$(SERVER:.c=.o)

all: $(NAME)

$(NAME): $(O_SERVER)
	$(CC) $(FLAGS) $(O_SERVER) -o server

#		$(NAME2): 
#			$(CC) $(FLAGS) $(O_CLIENT) -o server

clean:
	rm *.o

fclean: clean
	rm server
#	rm client

re: fclean
	make

.PHONY: all clean fclean re
