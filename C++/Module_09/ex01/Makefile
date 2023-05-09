# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 19:48:32 by ccantale          #+#    #+#              #
#    Updated: 2023/05/09 20:12:49 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		g++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

NAME		=		RPN

SRCS		=		main.cpp \
				RPN.cpp

OBJDIR		=		obj
OBJS		=		$(addprefix OBJDIR/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $(NAME)

$(OBJS): $(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $(addprefix $(OBJDIR/, $(<:.cpp=.o)))

clean: 
	rm -rf $(OBJDIR)

flcean:
	rm $(NAME)

kill: clean fclean

re: kill
	make

.PHONY: all clean fclean kill re
