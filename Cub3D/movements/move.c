/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:35:06 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/19 01:31:33 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	move_forward(void)
{
	char const	**map = get_map();
	double		x;
	double		y;
	double		dir[2];
	double		speed;

	x = get_player_x();
	y = get_player_y();
	dir[X] = get_player_dirx();
	dir[Y] = get_player_diry();
	speed = (double)get_delta_time() * SPEED;
	if (map[(int)(y)][(int)(x + dir[X] * speed)] == '0'
			&& map[(int)(y + dir[Y] * speed)][(int)(x)] == '0')
	{
		update_player_pos(x + dir[X] * speed, y + dir[Y] * speed);
	}
}

void	move_back(void)
{
	char const	**map = get_map();
	double		x;
	double		y;
	double		dir[2];
	double		speed;

	x = get_player_x();
	y = get_player_y();
	dir[X] = get_player_dirx();
	dir[Y] = get_player_diry();
	speed = (double)get_delta_time() * SPEED;
	if (map[(int)(y)][(int)(x - dir[X] * speed)] == '0'
			&& map[(int)(y - dir[Y] * speed)][(int)(x)] == '0')
	{
		update_player_pos(x - dir[X] * speed, y - dir[Y] * speed);
	}
}

void	move_left(void)
{
	char const	**map = get_map();
	double		x;
	double		y;
	double		dir[2];
	double		speed;

	x = get_player_x();
	y = get_player_y();
	dir[X] = get_player_diry();
	dir[Y] = get_player_dirx() * -1;
	speed = (double)get_delta_time() * SPEED;
	if (map[(int)(y)][(int)(x + dir[X] * speed)] == '0'
			&& map[(int)(y + dir[Y] * speed)][(int)(x)] == '0')
	{
		update_player_pos(x + dir[X] * speed, y + dir[Y] * speed);
	}
}

void	move_right(void)
{
	char const	**map = get_map();
	double		x;
	double		y;
	double		dir[2];
	double		speed;

	x = get_player_x();
	y = get_player_y();
	dir[X] = get_player_diry() * -1;
	dir[Y] = get_player_dirx();
	speed = (double)get_delta_time() * SPEED;
	if (map[(int)(y)][(int)(x + dir[X] * speed)] == '0'
			&& map[(int)(y + dir[Y] * speed)][(int)(x)] == '0')
	{
		update_player_pos(x + dir[X] * speed, y + dir[Y] * speed);
	}
}
