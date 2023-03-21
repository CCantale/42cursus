/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:20:48 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 20:14:49 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "side_handler.h"

static t_side	*side_handler(int axis_hit, int wall_position, t_side option)
{
	static t_side	side[WINDOW_WIDTH];
	static int		i;

	if (option == s_ADD_SIDE && axis_hit == X)
	{
		if ((int)get_player_x() - wall_position > 0)
			side[i++] = s_EAST;
		else
			side[i++] = s_WEST;
	}
	if (option == s_ADD_SIDE && axis_hit == Y)
	{
		if ((int)get_player_y() - wall_position > 0)
			side[i++] = s_SOUTH;
		else
			side[i++] = s_NORTH;
	}
	else if (option == s_GET_SIDE)
	{
		return (side);
	}
	if (i >= WINDOW_WIDTH)
		i = 0;
	return (0);
}

void	add_ray_side(int axis_hit, int position)
{
	side_handler(axis_hit, position, s_ADD_SIDE);
}

t_side	*get_side(void)
{
	return (side_handler(0, 0, s_GET_SIDE));
}
