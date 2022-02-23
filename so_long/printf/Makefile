# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 22:43:01 by ccantale          #+#    #+#              #
#    Updated: 2022/02/23 14:19:17 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror

NAME = libftprintf
FILES = ft_printf.c c_printf.c s_p_printf.c d_u_printf.c i_printf.c x_X_printf.c

TEST = printest
OBJ = $(FILES:.c=.o)

all: $(NAME).a

$(NAME).a: $(OBJ)
	make -C libft
	cp libft/libft.a ./$(NAME).a
	ar rcs $@ $^
	ranlib $(NAME).a

$(OBJ): $(FILES)
	$(CC) -c $(FILES)

clean: $(NAME).a
	make fclean -C libft
	rm $(OBJ)

fclean: clean
	rm $(NAME).a

re: fclean
	make

bonus: all

test: printest.o

printest.o: $(NAME).a
	$(CC) -c $(TEST).c
	$(CC) $(NAME).a $(TEST).o -o test
	./test

testclean: printest.o fclean
	rm printest.o test

.PHONY: all clean fclean re test printest
