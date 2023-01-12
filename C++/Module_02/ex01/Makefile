# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:07:12 by ccantale          #+#    #+#              #
#    Updated: 2023/01/12 18:12:04 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		g++
FLAGS		=		-Wall -Wextra  -Werror -std=c++98

NAME		=		fixed_point_nbr

SRC			=		main.cpp Fixed.cpp

OBJS		=		$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm *.o

fclean:
	rm $(NAME)

re: clean fclean
	make

.PHONY: all clean fclean re
