# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:57:41 by ccantale          #+#    #+#              #
#    Updated: 2022/08/11 23:59:36 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libft
FILES = ft_putnbr_fd.c ft_putstr_fd.c \
		ft_putchar_fd.c ft_strlcpy.c \
		ft_atoi.c ft_calloc.c\
		ft_strlen.c \
		printf/ft_printf.c printf/c_printf.c \
		printf/d_u_printf.c printf/i_printf.c \
		printf/s_p_printf.c printf/x_X_printf.c 

OBJ = $(FILES:.c=.o)

all: $(NAME).a

$(NAME).a: $(OBJ)
	ar rcs $(NAME).a $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: $(NAME).a
	rm *.o
	rm printf/*.o

fclean: clean
	rm $(NAME).a

re: fclean
	make

.PHONY: all clean fclean re
