# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 16:11:17 by ccantale          #+#    #+#              #
#    Updated: 2023/07/01 20:43:44 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		g++
FLAGS		=		-Wall -Wextra -Werror -std=c++98
INCL		=		-I. -Iincludes
LINK		=		-L.

NAME		=		PmergeMe

SRCS		=		srcs/main.cpp \
				srcs/PmergeMe.cpp

OBJDIR		=		obj
OBJS		=		$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(NAME)
	@echo Program successfully compiled!

$(NAME): $(OBJS)
	@$(CC) $(LINKS) $^ -o $(NAME)

$(OBJS): $(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(INCL) -c $< -o $(addprefix $(OBJDIR)/, $(<:.cpp=.o))

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm $(NAME)

kill: clean fclean
	@echo Everithyng was successfully disintegrated

re: kill all
	@echo ... and recompiled!

go: $(NAME)
	@./$(NAME)

.PHONY: all clean fclean kill re go
	
