# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:57:41 by ccantale          #+#    #+#              #
#    Updated: 2022/02/23 17:39:59 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libft
FILES = ft_isalpha.c ft_isdigit.c \
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
		ft_strtrim.c ft_split.c \
	 	ft_calloc.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c \
	 	ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c \
		ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c \
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
