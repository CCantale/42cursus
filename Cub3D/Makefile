# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 17:01:39 by ccantale          #+#    #+#              #
#    Updated: 2023/02/27 15:46:26 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc
FLAGS		=		-Wall -Wextra -Werror -g

NAME		=		cub3D

SRC			=		main.c \
					error/error_msg.c error/error_null.c \
					map_checks/check_map.c \
					utils/cub_calloc.c utils/cub_join.c \
					utils/cub_split.c utils/cub_strdup.c \
					utils/cub_strlen.c utils/cub_strncpy.c \
					utils/cub_substr.c utils/cub_strcmp.c \
					utils/cub_atoi.c \
					cantalloc/cantalloc.c cantalloc/cantalloc_dup.c \
					cantalloc/ccantalloc.c \
					static_handlers/static_handlers_init.c \
					static_handlers/map_handler.c \
					static_handlers/texture_handler.c \
					static_handlers/get_texture.c \
					static_handlers/color_handler.c \
					static_handlers/game_handler.c \
					static_handlers/player_handler.c \
					static_handlers/get_player.c \
					static_handlers/camera_handler.c \
					static_handlers/time_handler.c \
					static_handlers/side_handler.c \
					static_handlers/key_handler.c \
					game/update.c \
					game/event.c \
					raycasting/get_walls.c \
 					renderer/render_background.c \
					renderer/render.c \
					movements/rotate.c \
					movements/move.c

OBJDIR		=		obj
OBJ			=		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

MINIDIR		=		minilibX
MINI		=		$(MINIDIR)/libmlx.a



all: $(MINI) $(NAME)

$(MINI):
	make -C $(MINIDIR)

$(NAME): $(OBJ)
	$(CC) $^ -o $@ -lmlx -framework openGL -framework AppKit

$(OBJ): $(OBJDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $(addprefix $(OBJDIR)/, $(<:.c=.o))

clean:
	rm -rf $(OBJDIR)

fclean:
	rm $(NAME)

kill: clean fclean

re: kill
	make

play: $(MINI) $(NAME)
	./cub3D tests/map.cub

.PHONY: all clean fclean kill re play
