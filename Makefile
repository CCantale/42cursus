# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:57:41 by ccantale          #+#    #+#              #
#    Updated: 2022/01/11 14:37:31 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft
ANAME = libft.a
HNAME = libft.h
CFILES = ft_isalpha.c ft_isdigit.c
OFILES = $(CFILES:.c=.o) libft.o
TFILES = test.c stdfunc.c
OT_FILES = $(TFILES:.c=.o) stdfunc.o

all: $(ANAME)

$(ANAME): $(OFILES)
	ar rcs $(ANAME) $(OFILES)

$(OFILES):
	$(CC) $(CFLAGS) -c $(CFILES)
	$(CC) $(CFLAGS) -c $(HNAME) -o $(NAME).o

clean:
	rm *.o $(ANAME)

fclean:
	rm -f $(OFILES) $(ANAME)

test: $(ANAME) main.o
	$(CC) $(CFLAGS) $(ANAME) $(OT_FILES) stdfunc.o -o test
	./test

main.o: $(TFILES) stdfunc.h
	$(CC) $(CFLAGS) -c $(TFILES)
	$(CC) $(CFLAGS) -c stdfunc.h -o stdfunc.o

totalclean: clean
	rm test


