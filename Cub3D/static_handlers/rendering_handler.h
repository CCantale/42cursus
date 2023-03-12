/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_handler.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:19:52 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/12 13:32:04 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_HANDLER_H
# define RENDERING_HANDLER_H

# include "../global_headers/common.h"
# include "../global_headers/game_info.h"
# include "../global_headers/game.h"
# include "../minilibX/mlx.h"

typedef enum e_render
{
	ren_PIXEL_PUT,
	ren_RENDER,
	ren_DESTROY
}	t_render;

typedef struct s_image
{
	void const	*image;
	char const	*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

#endif
