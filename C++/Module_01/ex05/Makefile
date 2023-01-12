# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 11:36:05 by ccantale          #+#    #+#              #
#    Updated: 2023/01/12 11:36:08 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		g++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

NAME		=		harl

SRC		=		main.cpp Harl.cpp

OBJS		=		$(SRC:.cpp=.o)



all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm *.o

fclean:
	rm $(NAME)

re: clean fclean
	make

.PHONY: all clean fclean re
