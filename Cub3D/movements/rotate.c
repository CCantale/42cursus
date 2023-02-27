/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:33:11 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 09:39:37 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate.h"

void	rotate(t_rotation direction)
{
	double 	speed;
	
	speed = (get_delta_time() / 1000.0) * ROTATION_SPEED;
	if (direction == r_LEFT)
		speed *= -1;
	update_player_dir(
			get_player_dirx() * cos(speed) - get_player_diry() * sin(speed),
			get_player_dirx() * sin(speed) + get_player_diry() * cos(speed));
	update_camera_plan(
			get_camera_x() * cos(speed) - get_camera_y() * sin(speed),
			get_camera_x() * sin(speed) + get_camera_y() * cos(speed));
}





