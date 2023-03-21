/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_handler.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:19:52 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 16:55:12 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_HANDLER_H
# define RENDERING_HANDLER_H

# include "../global_headers/common.h"
# include "../global_headers/game_info.h"
# include "../global_headers/game.h"
# include "../global_headers/image_struct.h"
# include "../minilibX/mlx.h"

void	draw_pixels(void);

typedef enum e_render
{
	ren_PIXEL_PUT,
	ren_RENDER,
	ren_DESTROY
}	t_render;

#endif
