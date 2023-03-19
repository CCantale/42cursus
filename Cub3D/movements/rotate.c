/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:33:11 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/19 01:04:52 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate.h"

void	rotate(t_rotation direction)
{
	double	speed;
	double	new_dirx;
	double	new_diry;
	double	new_camx;
	double	new_camy;

	speed = get_delta_time() * ROTATION_SPEED;
	if (direction == r_LEFT)
		speed *= -1;
	new_dirx = get_player_dirx() * cos(speed) - get_player_diry() * sin(speed);
	new_diry = get_player_dirx() * sin(speed) + get_player_diry() * cos(speed);
	new_camx = get_camera_x() * cos(speed) - get_camera_y() * sin(speed);
	new_camy = get_camera_x() * sin(speed) + get_camera_y() * cos(speed);
	update_player_dir(new_dirx, new_diry);
	update_camera_plan(new_camx, new_camy);
}
