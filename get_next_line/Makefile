# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 17:35:53 by ccantale          #+#    #+#              #
#    Updated: 2022/01/27 23:45:02 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFFER = 3
CC = gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER)

NAME = get_next_line
FILES = get_next_line_utils.c get_next_line.h

all:
	$(CC) $(NAME).c $(FILES)
	lldb ./a.out

clean:
	rm *.gch

fclean: 
	rm *.gch a.out
