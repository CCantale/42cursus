/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:25:11 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/12 18:53:38 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
											#include <stdio.h>
											void	draw_pixel(int x, int y, int color);
											void	render_static();

void	render(void)
{
	double const	*walls = get_walls();
	int				vertical_line_length;
	int				vertical_line_end;
	int				x;
	int				y;

	render_background();
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		vertical_line_length = (int)(WINDOW_HEIGHT / walls[x]);
		y = (WINDOW_HEIGHT - vertical_line_length) / 2;
		if (y < 0)
			y = 0;
		vertical_line_end = y + vertical_line_length;
		while (y < WINDOW_HEIGHT && y < vertical_line_end)
		{
			if (get_side()[x] == s_NORTH)
				draw_pixel(x, y, 0xFFFFFF);
			else if (get_side()[x] == s_SOUTH)
				draw_pixel(x, y, 0x000000);
			else if (get_side()[x] == s_EAST)
				draw_pixel(x, y, 0xFFFFFF / 3 + 100);
			else
				draw_pixel(x, y, 0xFFFFFF / 3 + 300);
			++y;
		}
		++x;
	}
	render_static();
}
