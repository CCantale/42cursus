# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 19:14:21 by ccantale          #+#    #+#              #
#    Updated: 2022/09/27 18:09:37 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		gcc
FLAGS	=		-Wall -Wextra -Werror #-fsanitize=address -g3


NAME	=		philo

FILES	=		main.c \
				messages.c \
				inform.c \
				utilitarianism.c \
				debug.c \
				quit.c \
				dinner.c \
				routine.c \
				wait_for_k.c

OBJDIR	=		obj
SRCDIR	=		src

SRC		=		$(FILES:%=$(SRCDIR)/%)
OBJ		=		$(FILES:%.c=$(OBJDIR)/%.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p obj
	$(CC) $(FLAGS) -g -c $< -o $@

clean:
	rm -r obj

fclean:
	rm $(NAME)

re: $(NAME) fclean
	rm -r obj
	make

go:
	make
	./philo 4 420 200 200

l:
	make
	leaks --atExit -- ./philo 4 420 200 200
	
seg:
	make
	lldb ./philo -- 4 420 200 200

.PHONY: all clean fclean re go l seg

