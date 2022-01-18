# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:57:41 by ccantale          #+#    #+#              #
#    Updated: 2022/01/18 14:44:20 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft
CFILES = ft_isalpha.c ft_isdigit.c \
		 ft_isalnum.c ft_isascii.c \
		 ft_isprint.c ft_strlen.c \
		 ft_memset.c ft_bzero.c \
		 ft_memcpy.c ft_memmove.c \
		 ft_strlcpy.c ft_strlcat.c \
		 ft_toupper.c ft_tolower.c \
		 ft_strchr.c ft_strrchr.c \
		 ft_strncmp.c ft_memchr.c \
		 ft_memcmp.c ft_strnstr.c \
		 ft_atoi.c ft_strdup.c \
		 ft_substr.c ft_strjoin.c \
		 ft_strtrim.c ft_split.c
OFILES = $(CFILES:.c=.o) libft.o
TNAME = test
TFILES = $(TNAME).c stdfunc.c
OT_FILES = $(TFILES:.c=.o)

all: $(NAME).a

$(NAME).a: $(OFILES)
	ar rcs $(NAME).a $(OFILES)

$(OFILES): $(CFILES) libft.h
	$(CC) $(CFLAGS) -c $(CFILES)
	$(CC) $(CFLAGS) -c $(NAME).h -o $(NAME).o

clean: $(NAME).a
	rm *.o

fclean: clean
	rm $(NAME).a

re: fclean
	make

testclean: test fclean
	rm test

test: $(NAME).a $(TNAME).o
	$(CC) $(CFLAGS) $(NAME).a $(OT_FILES) -o test
	./test

$(TNAME).o: $(TFILES)
	$(CC) $(CFLAGS) -c $(TFILES)

stdfunc.o: stdfunc.c
	$(CC) $(CFLAGS) -c stdfunc.h -o stdfunc.o
