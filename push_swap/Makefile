# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 16:24:46 by ccantale          #+#    #+#              #
#    Updated: 2022/08/16 15:14:44 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		gcc
FLAGS	=		-Wall -Wextra -Werror

NAME	=		push_swap

FILES	=		main.c \
				utils.c \
				get_swap.c \
				right_swap.c \
				two_three_five_swap.c \
				sa_ra_rra_swap.c \
				stack_atoi.c \
				lis_swap.c \
				first_then_swap.c \
				start_swap.c \
				rev_swap.c \
				prof_swap.c \
				end_swap.c \
				arrr.c \
				scroll_swap.c

OBJ		=		$(FILES:.c=.o)

LIBFT	=		libft/libft.a



all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft
	make clean -C libft

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ $(LIBFT) 

%.o: %.c
	$(CC) $(FLAGS) -g -c $(FILES)

clean:
	rm *.o

fclean:
	rm $(NAME)

re: clean
	make

n:
	@norminette

.PHONY: all clean fclean re n
