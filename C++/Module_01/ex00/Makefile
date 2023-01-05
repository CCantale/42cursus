# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 23:53:53 by ccantale          #+#    #+#              #
#    Updated: 2023/01/06 00:06:18 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		g++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

SRC			=		main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS		=		$(SRC:.cpp=.o)

NAME		=		BraiiiiiiinnnzzzZ

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm *.o

fclean:
	rm $(NAME)

re: clean fclean
	make

go:
	make
	./$(NAME)

.PHONY: clean fclean re go
