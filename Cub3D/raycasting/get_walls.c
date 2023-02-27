/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 01:45:05 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 09:27:17 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_walls.h"

void			add_side(int option);
static double	start_raycasting(size_t ray_nbr);
static double	cast_ray_get_wall_height(
		double direction[2], int closest_border_to_player[2], double step[2]);
static double	raycasting_algorithm(
					double closest_border_to_ray[2], short step_on_map[2],
					double step_length[2], int closest_border_to_player[2]);
/* end of declarations */

/* this function is called by the renderer */
double	*get_walls(void)
{
	size_t	i;
	double		*walls;

	walls = malloc(sizeof(double) * WINDOW_WIDTH);
	if (!walls)
		return (NULL);
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		walls[i] = start_raycasting(i);
		++i;
	}
	return (walls);
}

static double	get_step_length(double ray_direction)
{
	if (ray_direction != 0)
		return (fabs(1 / ray_direction));
	else
		return (10000);
}

static double	start_raycasting(size_t ray_nbr)
{
	double	ray_val;
	double	ray_direction[2];
	int		closest_border_to_player[2];
	double	ray_step_length[2];

	ray_val = 2 * ray_nbr / (double)WINDOW_WIDTH - 1;
	ray_direction[X] = get_player_dirx() + get_camera_x() * ray_val;
	ray_direction[Y] = get_player_diry() + get_camera_y() * ray_val;
	closest_border_to_player[X] = (int)get_player_x();
	closest_border_to_player[Y] = (int)get_player_y();
	ray_step_length[X] = get_step_length(ray_direction[X]);
	ray_step_length[Y] = get_step_length(ray_direction[Y]);
	return (cast_ray_get_wall_height(
										ray_direction,
										closest_border_to_player,
										ray_step_length
									));
}

/* If not specified, all names here are referring to the ray
** and to where it got so far, not to it's origin (player) */
static double	cast_ray_get_wall_height(
		double direction[2], int closest_border_to_player[2], double step[2])
{
	double	closest_border_to_ray[2];
	short	step_on_map[2];

	step_on_map[X] = 1;
	step_on_map[Y] = 1;
	if (direction[X] < 0)
		step_on_map[X] = -1;
	if (direction[Y] < 0)
		step_on_map[Y] = -1;
	if (direction[X] < 0)
		closest_border_to_ray[X] =
			(closest_border_to_player[X] - get_player_x()) * step[X];
	else
		closest_border_to_ray[X] =
			(get_player_x() + 1.0 - closest_border_to_player[X]) * step[X];
	if (direction[Y] < 0)
		closest_border_to_ray[Y] =
			(closest_border_to_player[Y] - get_player_y()) * step[Y];
	else
		closest_border_to_ray[Y] =
			(get_player_y() + 1.0 - closest_border_to_player[Y]) * step[Y];
	return(raycasting_algorithm(
				closest_border_to_ray,
				step_on_map, step,
				closest_border_to_player));
}
	
static double	raycasting_algorithm(
	double closest_border_to_ray[2], short step_on_map[2],
	double step_length[2], int closest_border_to_player[2])
{
	char const	**map = get_map();
	bool		hit;
	int			axis_hit;

	hit = false;
	while (hit == false)
	{
		if (closest_border_to_ray[X] < closest_border_to_ray[Y])
		{
			closest_border_to_ray[X] += step_length[X];
			closest_border_to_player[X] += step_on_map[X];
			axis_hit = X;
		}
		else
		{
			closest_border_to_ray[Y] += step_length[Y];
			closest_border_to_player[Y] += step_on_map[Y];
			axis_hit = Y;
		}
		if (map[closest_border_to_player[Y]][closest_border_to_player[X]] == '1')
			hit = true;
	}
	add_side(axis_hit);
	return (closest_border_to_ray[axis_hit] - step_length[axis_hit]);
}




