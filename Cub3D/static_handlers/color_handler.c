/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:27:13 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 21:35:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_handler.h"

static t_texture	make_color(char *input_line, t_color option);
/* end of declarations */

static int	*color_handler(t_color option)
{
	static int	floor[3] = {-1, -1, -1};
	static int	ceiling[3] = {-1, -1, -1};
	static int	floor_int;
	static int	ceiling_int;

	if (option == c_GET_FLOOR_ARRAY)
		return (floor);
	else if (option == c_GET_CEILING_ARRAY)
		return (ceiling);
	else if (option == c_GET_FLOOR)
	{
		floor_int = floor[0] << 16 | floor[1] << 8 | floor[2];
		return (&floor_int);
	}
	else if (option == c_GET_CEILING)
	{
		ceiling_int = ceiling[0] << 16 | ceiling[1] << 8 | ceiling[2];
		return (&ceiling_int);
	}
	return (0);
}

static t_texture	make_color(char *input_line, t_color option)
{
	int		*color;
	size_t	i;

	color = NULL;
	while (*input_line == ' ')
		++input_line;
	color = color_handler(option);
	if (*color != -1)
		return (tex_COLOR_REPEATED);
	i = 0;
	while (i < 3)
	{
		while (*input_line < '0' || *input_line > '9')
		{
			if (*input_line != ' ' && *input_line != ',')
				return (tex_ERROR);
			++input_line;
		}
		color[i] = cub_atoi(input_line);
		//if (color[i] < 0 || color[i] > 255)
		//	return (tex_ERROR);
		while (*input_line >= '0' && *input_line <= '9')
			++input_line;
		++i;
	}
	return (tex_COLOR_OK);
}

t_texture	get_color(char *input_line)
{
	if (cub_strcmp(input_line, "F ") == 0)
	{
		return (make_color(input_line + 1, c_GET_FLOOR_ARRAY));
	}
	else if (cub_strcmp(input_line, "C ") == 0)
	{
		return (make_color(input_line + 1, c_GET_CEILING_ARRAY));
	}
	return (tex_COLOR_OK);
}

int	get_ceiling_color(void)
{
	return (*color_handler(c_GET_CEILING));
}

int	get_floor_color(void)
{
	return (*color_handler(c_GET_FLOOR));
}
