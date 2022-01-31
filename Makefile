# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 22:43:01 by ccantale          #+#    #+#              #
#    Updated: 2022/01/31 03:42:21 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror

NAME = libftprintf
FILES = ft_printf.c c_s.c

TEST = printest
OBJ = $(FILES:.c=.o) $(NAME).o

all: $(NAME).a

$(NAME).a: $(OBJ)
	make -C libft
	cp libft/libft.a ./$(NAME).a
	make fclean -C libft
	ar rcs $@ $^
	ranlib $(NAME).a

$(OBJ): $(FILES) $(NAME).h
	$(CC) -c $(FILES)
	$(CC) -c $(NAME).h -o $(NAME).o

clean: all
	rm $(OBJ)

fclean: clean
	rm $(NAME).a

re: fclean
	make

test: printest

printest: all
	$(CC) -c $(TEST).c
	$(CC) $(NAME).a $(TEST).o -o test
	./test

testclean: printest fclean
	rm printest.o test

.PHONY: all clean fclean re test printest
