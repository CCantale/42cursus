/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:30:17 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/26 02:32:48 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_HANDLER_H
# define CAMERA_HANDLER_H

# include "../global_handlers/player.h"

typedef enum e_camera
{
	cam_UPDATE,
	cam_GETX,
	cam_GET_Y
}	t_camera;

#endif
