################################################################################
#																			   #
#		Claudio Cantale							claudio.cantale93@gmail.com	   #
#																			   #
################################################################################

CC		=	g++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS	=	$(SRC:.cpp=.o)

NAME	=	violence

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
