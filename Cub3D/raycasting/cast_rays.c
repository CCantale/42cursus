/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 01:45:05 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/26 13:56:33 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_rays.h"

static int	cast_ray_return_height(size_t ray_nbr, double camera_plane[2]);
/* end of declarations */

/* this function is called by the renderer */
int	*cast_rays(void)
{
	size_t	i;
	int		*walls;
	double	camera_plane[2];

	walls = malloc(sizeof(int) * WINDOW_WIDTH);
	if (!walls)
		return (NULL); /////
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		walls[i] = raycast_algorithm(i, camera_plane);
			++i;
	}
	return (walls);
}

static double	get_step_length(double ray_direction)
{
	if (ray_direction != 0)
		return (abs(1 / ray_direction));
	else
		return (10000);
}

static int	raycast_algorithm(size_t ray_nbr, double camera_plane[2])
{
	double	ray_val;
	double	ray_direction[2];
	int		nearest_border_to_player[2];
	double	ray_step_length[2];

	ray_val = 2 * ray_nbr / WINDOW_WIDTH - 1;
	ray_direction[X] = get_player_x() + get_camera_x() * ray_val;
	ray_direction[Y] = get_player_y() + get_camera_y() * ray_val;
	nearest_border_to_player[X] = (int)get_player_x();
	nearest_border_to_player[Y] = (int)get_player_y();
	ray_step_length[X] = get_step_length(ray_direction[X]);
	ray_step_length[Y] = get_step_length(ray_direction[Y]);
	return (cast_ray_get_wall_height(
										ray_direction,
										nearest_border_to_player,
										ray_step_length
									));
}

static void	set_step_and_nearest_border(
		short step[2], double nearest_border[2],
		int nearest_border_to_player[2], double direction[2])
{

/* If not specified, all names here are referring to the ray
 * and to where it got so far, not to it's origin (player) */
static double	cast_ray_get_wall_height(
		double direction[2], int nearest_border_to_player[2], double step[2])
{
	double	nearest_border_to_ray[2];
	short	step_on_map[2];

	step_on_map[X] = 1;
	step_on_map[Y] = 1;
	if (direction[X] < 0)
		step_on_map[X] = -1;
	if (direction[Y] < 0)
		step_on_map[Y] = -1;
	if (direction[X] < 0)
		nearest_border_to_ray[X] =
			(nearest_border_to_player[X] - get_player_x()) * step[X];
	else
		nearest_border_to_ray[X] =
			(get_player_x() + 1.0 - nearest_border_to_player[X]) * step[X];
	if (direction[Y] < 0)
		nearest_border_to_ray[Y] =
			(nearest_border_to_player[Y] - get_player_y()) * step[Y];
	else
		nearest_border_to_ray[Y] =
			(get_player_y() + 1.0 - nearest_border_to_player[Y]) * step[Y];
	return(raycasting_algorithm(
				nearest_border_to_ray,
				step_on_map, step,
				nearest_border_to_player
				);
}
	
static double	raycasting_algorithm(
	double nearest_border_to_ray[2], short step_on_map[2], double step_length[2]
	t_axis	axis_hit;
	hit = false;


