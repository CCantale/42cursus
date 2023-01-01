# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 19:11:19 by ccantale          #+#    #+#              #
#    Updated: 2023/01/01 19:22:13 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		c++
FLAGS	=		-Wall -Wextra -Werror

NAME	=		phonebook

SRC		=		Contact.cpp PhoneBook.cpp main.cpp
OBJ		=		$(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $^

clean:
	rm *.o

fclean:
	rm $(NAME)

re: clean fclean
	make

.PHONY: all clean fclean re
