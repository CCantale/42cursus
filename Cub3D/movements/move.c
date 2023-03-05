/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:35:06 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/05 02:02:10 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
									#include <stdio.h>

void	move_up(void)
{
	char const	**map = get_map();
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		speed;

	x = get_player_x();
	y = get_player_y();
	dirx = get_player_dirx();
	diry = get_player_diry();
	speed = SPEED / 3;
	//speed = (get_delta_time() / 1000) * SPEED;
	//if (speed > 0.2 * SPEED || speed == 0)
		//speed = 0.2 * SPEED;

		//printf("%d\n", (int)(x + dirx * speed));
		//printf("%d\n", (int)(y + diry * speed));
		//printf("x = %d\n", (int)x);
		//printf("y = %d\n", (int)y);
	if (map[(int)(y)][(int)(x + dirx * speed)] == '0'
			&& map[(int)(y + diry * speed)][(int)(x)] == '0')
	{
		//printf("QUI\n");
		update_player_pos(x + dirx * speed, y + diry * speed);
	}
}
