/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:54:19 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/12 18:22:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_background.h"
void	draw_pixel(int x, int y, int color);
void	render_static();

static void	render(int color)
{
	int	endpoint;
	int	x;
	int	y;

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
			draw_pixel(x, y, color);
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

