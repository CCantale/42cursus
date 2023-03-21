/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:40:53 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 20:08:07 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_HANDLER_H
# define TEXTURE_HANDLER_H

# define TEX_NUMBER	4

# include "../global_headers/common.h"
# include "../global_headers/game.h"
# include "../global_headers/side.h"
# include "../global_headers/texture.h"
# include "../global_headers/image_struct.h"
# include "../minilibX/mlx.h"

typedef enum e_texture
{
	tex_NORTH,
	tex_SOUTH,
	tex_GET_EAST,
	tex_GET_WEST,
	tex_UPDATE,
	tex_ERROR,
	tex_COLOR_OK,
	tex_COLOR_REPEATED,
	tex_DESTROY
}	t_texture;

int			error_msg(char *msg);
int			cub_strcmp(char *s1, char *s2);
t_texture	get_color(char *input_line);

#endif
