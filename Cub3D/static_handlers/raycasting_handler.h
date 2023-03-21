/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_handler.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:14:10 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 20:19:47 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_HANDLER_H
# define RAYCASTING_HANDLER_H

# include "../global_headers/common.h"
# include "../global_headers/game_info.h"

double	raycasting(size_t ray_nbr);

typedef enum e_raycasting
{
	ray_GET_WALLS
}	t_raycasting;

#endif
