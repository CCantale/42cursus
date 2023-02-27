/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:19:05 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 07:13:35 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_handler.h"

static double	camera_handler(double x, double y, t_camera option)
{
	static double	camera_plan_x;
	static double	camera_plan_y;

	if (option == cam_UPDATE)
	{
		camera_plan_x = x;
		camera_plan_y = y;
	}
	else if (option == cam_GET_X)
	{
		return (camera_plan_x);
	}
	else if (option == cam_GET_Y)
	{
		return (camera_plan_y);
	}
	return (0);
}
void	init_camera_plan(void)
{
	if (get_player_dirx() == 0 && get_player_diry() == -1)
	{
		update_camera_plan(FOV_SIZE, 0);
	}
	else if (get_player_dirx() == 0 && get_player_diry() == 1)
	{
		update_camera_plan(-FOV_SIZE, 0);
	}
	else if (get_player_dirx() == -1 && get_player_diry() == 0)
	{
		update_camera_plan(0, -FOV_SIZE);
	}
	else if (get_player_dirx() == 1 && get_player_diry() == 0)
	{
		update_camera_plan(0, FOV_SIZE);
	}
}

void	update_camera_plan(double x, double y)
{
	camera_handler(x, y, cam_UPDATE);
}

double	get_camera_x(void)
{
	return (camera_handler(0, 0, cam_GET_X));
}

double	get_camera_y(void)
{
	return (camera_handler(0, 0, cam_GET_Y));
}
