/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:25:11 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/20 16:43:21 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
											#include <stdio.h>

static int	get_texture_x(int x, double wall_value)
{
	t_side const	*side = get_side();
	double			ray_val;
	double			ray_direction[2];
	double			wall_hit_point;
	int				texture_x;

	ray_val = 2 * x / (double)WINDOW_WIDTH - 1;
	ray_direction[X] = get_player_dirx() + get_camera_x() * ray_val;
	ray_direction[Y] = get_player_diry() + get_camera_y() * ray_val;
	if (side[x] == s_EAST || side[x] == s_WEST)
		wall_hit_point =  get_player_y() + wall_value * ray_direction[Y];
	else
		wall_hit_point = get_player_x() + wall_value * ray_direction[X];
	wall_hit_point -= floor(wall_hit_point);
	texture_x = (int)(wall_hit_point * (double)get_texture(side[x])->width);
	return (texture_x);
}

static void	draw_single_line(int line_length, int x, int y, int texture_x) 
{
	t_side const	*side = get_side();
	int				line_end;
	int				texture_y;
	double			step;
	double 		 	starting_pos_on_texture;

	step = 1.0 * get_texture(side[x])->height / line_length;
	line_end = y + line_length;
	if (line_end >= WINDOW_HEIGHT)
		line_end = WINDOW_HEIGHT - 1;
	starting_pos_on_texture = (y - WINDOW_HEIGHT / 2 + line_length / 2) * step;
	while (y < WINDOW_HEIGHT && y < line_end)
	{
		texture_y = (int)starting_pos_on_texture & (get_texture(side[x])->height - 1);
		starting_pos_on_texture += step;
		draw_pixel(x, y, *(int *)(get_texture(side[x])->addr
				+ get_texture(side[x])->line_size * texture_y
				+ texture_x * (get_texture(side[x])->bits_per_pixel / 8)));
		++y;
	}
}

void	render(void) // da cambiare in una cosa tipo "draw_walls()"
{
	double const	*walls = get_walls();
	int				vertical_line_length;
	int				texture_x;
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
		texture_x = get_texture_x(x, walls[x]);
		draw_single_line(vertical_line_length, x, y, texture_x);
		++x;
	}
	render_static();
}
