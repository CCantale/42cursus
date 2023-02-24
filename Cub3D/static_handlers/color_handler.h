/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:34:49 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/24 23:28:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HANDLER_H
# define COLOR_HANDLER_H

# include "../common.h"
# include "../cantalloc/cantalloc.h"
# include "texture_handler.h"

typedef enum e_color
{
	c_MAKE_FLOOR,
	c_MAKE_CEILING,
	c_GET_FLOOR,
	c_GET_CEILING
}	t_color;

int	cub_strcmp(char *s1, char *s2);
int	cub_atoi(char *str);
t_texture	error_tex(char *msg);

#endif
