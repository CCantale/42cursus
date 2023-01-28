# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 01:00:55 by ccantale          #+#    #+#              #
#    Updated: 2023/01/28 21:18:56 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		g++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -g

NAME		=		bureaucrat

SRC			=		main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp

OBJ			=		$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:
	rm *.o

fclean:
	rm $(NAME)

kill: clean fclean

re: kill
	make

.PHONY: all clean fclean kill re
