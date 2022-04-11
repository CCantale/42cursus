# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 22:43:01 by ccantale          #+#    #+#              #
#    Updated: 2022/04/03 20:07:15 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror

NAME = libftprintf.a
FILES = ft_printf.c c_printf.c s_p_printf.c d_u_printf.c i_printf.c x_X_printf.c

TEST = printest
OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a ./$(NAME)
	ar rcs $@ $^
	ranlib $(NAME)

$(OBJ): $(FILES)
	$(CC) -c $(FILES)

clean: $(NAME)
	make fclean -C libft
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean
	make

bonus: all

test: printest.o

printest.o: $(NAME)
	$(CC) -c $(TEST).c
	$(CC) $(NAME) $(TEST).o -o test
	./test

testclean: printest.o fclean
	rm printest.o test

.PHONY: all clean fclean re test printest
