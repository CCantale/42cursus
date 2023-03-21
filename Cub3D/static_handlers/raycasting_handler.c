/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 10:09:39 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 20:19:04 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_handler.h"

static double const	*raycasting_handler(t_raycasting option)
{
	static double	walls[WINDOW_WIDTH];
	size_t			i;

	if (option == ray_GET_WALLS)
	{
		i = 0;
		while (i < WINDOW_WIDTH)
		{
			walls[i] = raycasting(i);
			++i;
		}
		return ((double const *)walls);
	}
	return (0);
}

double const	*get_walls(void)
{
	return (raycasting_handler(ray_GET_WALLS));
}
