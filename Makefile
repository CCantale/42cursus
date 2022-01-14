# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:57:41 by ccantale          #+#    #+#              #
#    Updated: 2022/01/15 00:15:11 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft
ANAME = libft.a
HNAME = libft.h
CFILES = ft_isalpha.c ft_isdigit.c \
		 ft_isalnum.c ft_isascii.c \
		 ft_isprint.c ft_strlen.c \
		 ft_memset.c ft_bzero.c \
		 ft_memcpy.c ft_memmove.c \
		 ft_strlcpy.c ft_strlcat.c \
		 ft_toupper.c ft_tolower.c \
		 ft_strchr.c
OFILES = $(CFILES:.c=.o) libft.o
TNAME = test
TFILES = $(TNAME).c stdfunc.c
OT_FILES = $(TFILES:.c=.o)

all: $(ANAME)

$(ANAME): $(OFILES)
	ar rcs $(ANAME) $(OFILES)

$(OFILES): $(CFILES) libft.h
	$(CC) $(CFLAGS) -c $(CFILES)
	$(CC) $(CFLAGS) -c $(HNAME) -o $(NAME).o

testclean: test clean
	rm test

clean: $(OFILES)
	rm *.o

fclean: clean $(ANAME)
	rm $(ANAME)

test: $(ANAME) $(TNAME).o
	$(CC) $(CFLAGS) $(ANAME) $(OT_FILES) -o test
	./test

$(TNAME).o: $(TFILES)
	$(CC) $(CFLAGS) -c $(TFILES)

stdfunc.o: stdfunc.c
	$(CC) $(CFLAGS) -c stdfunc.h -o stdfunc.o
