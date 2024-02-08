# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 14:18:11 by sahafid           #+#    #+#              #
#    Updated: 2023/01/07 01:59:32 by sahafid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



all : up

up : 
	@sudo docker-compose -f ./srcs/docker-compose.yml up 

down : 
	@sudo docker-compose -f ./srcs/docker-compose.yml down

stop : 
	@sudo docker-compose -f ./srcs/docker-compose.yml stop

start : 
	@sudo docker-compose -f ./srcs/docker-compose.yml start

status : 
	@sudo docker ps

kill:
	@sudo docker system prune -a
	@sudo rm -rf ../data/mariadb/* ../data/wordpress/*

re: kill up
