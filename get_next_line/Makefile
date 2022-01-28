# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 17:35:53 by ccantale          #+#    #+#              #
#    Updated: 2022/01/28 05:13:53 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFFER = 42
CC = gcc -Wall -Wextra -Werror
BSIZE = -D BUFFER_SIZE=$(BUFFER)

NAME = get_next_line
FILES = get_next_line_utils.c
OFILES = $(FILES:.c=.o) $(NAME)lib.o

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME).a $(OFILES)

$(OFILES):
	$(CC) $(BSIZE) -c $(NAME).c $(FILES)
	$(CC) -c $(NAME).h -o $(NAME)lib.o	

clean:
	rm *.o

fclean: all clean 
	rm $(NAME).a

re: fclean
	make
