/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:25:11 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/26 21:03:21 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
											#include <stdio.h>

void	render(void)
{
	double const	*walls = get_walls();
	int				vertical_line_length;
	int				vertical_line_end;
	int				x;
	int				y;

	if (!walls)
		return ;
	x = 0;
	while (x < WINDOW_WIDTH - 1)
	{
		vertical_line_length = (int)(WINDOW_HEIGHT * 11 * walls[x]);
		y = (WINDOW_HEIGHT - vertical_line_length) / 2;
		if (y < 0)
			y = 0;
		vertical_line_end = y + vertical_line_length;
		//printf("line length %d\nx %d - y %d\nend %d\n", vertical_line_length, x, y, vertical_line_end);
		while (y < WINDOW_HEIGHT && y < vertical_line_length)
		{
			mlx_pixel_put(get_game_init(), get_window(), x, y, 0xFFFFFF);
			++y;
		}
		++x;
	}
	free((void *)walls);
}
