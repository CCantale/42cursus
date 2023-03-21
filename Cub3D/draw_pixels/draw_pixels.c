/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:25:11 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 20:04:59 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_pixels.h"

static void	draw_single_color(int color)
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

static void	draw_background(void)
{
	draw_single_color(get_ceiling_color());
	draw_single_color(get_floor_color());
}

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
		wall_hit_point = get_player_y() + wall_value * ray_direction[Y];
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
	double			starting_pos_on_texture;

	step = 1.0 * get_texture(side[x])->height / line_length;
	line_end = y + line_length;
	if (line_end >= WINDOW_HEIGHT)
		line_end = WINDOW_HEIGHT - 1;
	starting_pos_on_texture = (y - WINDOW_HEIGHT / 2 + line_length / 2) * step;
	while (y < WINDOW_HEIGHT && y < line_end)
	{
		texture_y = (int)starting_pos_on_texture;
		starting_pos_on_texture += step;
		draw_pixel(x, y, *(int *)(get_texture(side[x])->addr
				+ get_texture(side[x])->line_size * texture_y
				+ texture_x * (get_texture(side[x])->bits_per_pixel / 8)));
		++y;
	}
}

void	draw_pixels(void)
{
	double const	*walls = get_walls();
	int				vertical_line_length;
	int				texture_x;
	int				x;
	int				y;

	draw_background();
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
}
