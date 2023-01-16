# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 15:52:47 by ccantale          #+#    #+#              #
#    Updated: 2023/01/16 17:46:13 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		g++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

NAME		=		scav_fight

SRC			=		main.cpp ClapTrap.cpp ScavTrap.cpp

OBJS		= 		$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm *.o

fclean:
	rm $(NAME)

re: clean fclean
	make

kill: clean fclean

.PHONY: all clean fclean re kill
