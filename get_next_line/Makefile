# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 17:35:53 by ccantale          #+#    #+#              #
#    Updated: 2022/01/27 17:42:20 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFFER = 42
CC = gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER)

NAME = get_next_line

all:
	$(CC) $(NAME).c -o $(NAME).o

clean:
	rm *.o

fclean:
	rm -f *.o
