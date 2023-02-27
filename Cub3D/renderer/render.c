/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:25:11 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 07:54:42 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
											#include <stdio.h>
											int	*get_side(void);

void	render(void)
{
	double const	*walls = get_walls();
	int				vertical_line_length;
	int				vertical_line_end;
	int				x;
	int				y;

	if (!walls)
		return ;
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
			if (get_side()[x] == X)
				mlx_pixel_put(get_game_init(), get_window(), x, y, 0xFFFFFF);
			else
				mlx_pixel_put(get_game_init(), get_window(), x, y, 0xFFFFFF / 3 + 100);
			++y;
		}
		++x;
	}
	free((void *)walls);
}
