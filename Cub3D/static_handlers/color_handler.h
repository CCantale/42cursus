/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:34:49 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 03:28:23 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HANDLER_H
# define COLOR_HANDLER_H

# include "../common.h"
# include "../cantalloc/cantalloc.h"
# include "texture_handler.h"

typedef enum e_color
{
	c_GET_FLOOR_ARRAY,
	c_GET_CEILING_ARRAY,
	c_GET_FLOOR,
	c_GET_CEILING
}	t_color;

int			cub_strcmp(char *s1, char *s2);
int			cub_atoi(char *str);
t_texture	error_tex(char *msg);

#endif
