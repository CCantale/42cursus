/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:54:19 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/08 16:48:56 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_background.h"

static void	render(int color)
{
	size_t	endpoint;
	size_t	x;
	size_t	y;

	if (color == get_ceiling_color())
	{
		y = 0;
		endpoint = WINDOW_HEIGHT / 2;
	}
	else
	{
		y = WINDOW_HEIGHT / 2;
		endpoint = WINDOW_HEIGHT;
	}
	while (y < endpoint)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mlx_pixel_put(get_game_init(), get_window(),
					x, y, color);
			++x;
		}
		++y;
	}
}

void	render_background(void)
{
	render(get_ceiling_color());
	render(get_floor_color());
}

