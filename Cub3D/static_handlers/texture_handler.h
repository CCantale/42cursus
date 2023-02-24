/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:40:53 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/24 23:48:12 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_HANDLER_H
# define TEXTURE_HANDLER_H

#include "../common.h"

typedef enum e_texture
{
	tex_GET_NORTH,
	tex_GET_SOUTH,
	tex_GET_WEST,
	tex_GET_EAST,
	tex_UPDATE,
	tex_ERROR,
	tex_COLOR_OK,
	tex_COLOR_REPEATED
} 	t_texture;

int			error_msg(char *msg);
int			cub_strcmp(char *s1, char *s2);
t_texture	get_color(char *input_line);

#endif
