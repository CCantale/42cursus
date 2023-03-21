/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 07:12:15 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 20:20:56 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_handler.h"

double	player_handler(double x, double y, t_player option)
{
	static double	pos_x;
	static double	pos_y;
	static double	dir_x;
	static double	dir_y;

	if (option == p_UPDATE_POS)
	{
		pos_x = x;
		pos_y = y;
	}
	else if (option == p_UPDATE_DIR)
	{
		dir_x = x;
		dir_y = y;
	}
	else if (option == p_GET_POSX)
		return (pos_x);
	else if (option == p_GET_POSY)
		return (pos_y);
	else if (option == p_GET_DIRX)
		return (dir_x);
	else if (option == p_GET_DIRY)
		return (dir_y);
	return (OK);
}

static void	set_direction_at_start(char direction)
{
	if (direction == 'N')
		update_player_dir(0, -1);
	else if (direction == 'S')
		update_player_dir(0, 1);
	else if (direction == 'W')
		update_player_dir(-1, 0);
	else if (direction == 'E')
		update_player_dir(1, 0);
}

void	init_player(void)
{
	char const	**map = get_map();
	size_t		x;
	size_t		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				update_player_pos(x + 0.5, y + 0.5);
				set_direction_at_start(map[y][x]);
				break ;
			}
			++x;
		}
		++y;
	}
}

void	update_player_pos(double x, double y)
{
	player_handler(x, y, p_UPDATE_POS);
}

void	update_player_dir(double x, double y)
{
	player_handler(x, y, p_UPDATE_DIR);
}
