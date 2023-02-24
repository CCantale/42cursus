/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:27:13 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/24 19:04:56 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_handler.h"

static int	*color_handler(int new_color[3], t_color option)
{
	static int	floor[3] = { -1, -1, -1 };
	static int	ceiliing[3] = { -1, -1, -1 };

	if (option == c_MAKE_FLOOR)
	{
		if (*floor == -1)
			floor = new_color;
		else
			return (floor);
	}
	else if (option == c_MAKE_CEILING)
	{
		if (*ceiling == -1)
			ceiling = new_color;
		else
			return (ceiling);
	}
	else if (option == c_GET_FLOOR)
		return (floor);
	else if (option == c_GET_CEILING)
		return (ceiling);
	return (NULL);
}

static t_texture	make_color(char *input_line, t_texture option)
{
	;
}


t_texture	get_color(char *input_line)
{
	if (cub_strcmp(input_line, "F ") == 0)
		return (make_color(input_line, c_MAKE_FLOOR));
	else if (cub_strcmp(input_line, "C ") == 0)
		return (make_color(input_line, c_MAKE_CEILING));
	return (tex_COLOR);
}

