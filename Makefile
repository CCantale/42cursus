# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 22:43:01 by ccantale          #+#    #+#              #
#    Updated: 2022/02/05 06:28:07 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror

NAME = libftprintf
FILES = ft_printf.c c_s_p.c

TEST = printest
OBJ = $(FILES:.c=.o) $(NAME).o

all: $(NAME).a

$(NAME).a: $(OBJ)
	make -C libft
	cp libft/libft.a ./$(NAME).a
	ar rcs $@ $^
	ranlib $(NAME).a

$(OBJ): $(FILES) $(NAME).h
	$(CC) -c $(FILES)
	$(CC) -c $(NAME).h -o $(NAME).o

clean: $(NAME).a
	make fclean -C libft
	rm $(OBJ)

fclean: clean
	rm $(NAME).a

re: fclean
	make

test: printest.o

printest.o: $(NAME).a
	$(CC) -c $(TEST).c
	$(CC) $(NAME).a $(TEST).o -o test
	./test

testclean: printest.o fclean
	rm printest.o test

.PHONY: all clean fclean re test printest
