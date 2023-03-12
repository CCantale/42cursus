/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:23:43 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/12 20:15:49 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_handler.h"
																#include <stdio.h>

static t_texture	define_which(char **line_from_set);
static int			update_textures(char **new_set, void *textures[5]);
static void			free_textures(void *textures[5]);
/* end of declarations */

/*
** textures[0] = north
** textures[1] = south
** textures[2] = west
** textures[3] = east
** textures[4] = 0
*/
void	*texture_handler(char **new_set, t_texture option)
{
	static void	*textures[5] = { NULL, NULL, NULL, NULL, NULL };

	if (option == tex_UPDATE)
	{
		if (!new_set || update_textures(new_set, textures) == NOT_OK)
			return (*new_set);
	}
	else
	{
		return (textures[option]);
	}
	return (NULL);
}

static int	update_textures(char **new_set, void *textures[5])
{
	size_t	i;
	int		which_one;

	i = 0;
	while (i < 6)
	{
		which_one = define_which(&new_set[i]);
		if (which_one == tex_ERROR)
		{
			free_textures(textures);
			return (error_msg("Syntax error. Wrong or missing parameter."));
		}
		if (textures[which_one] != NULL || which_one == tex_COLOR_REPEATED)
		{
			free_textures(textures);
			return (error_msg("Syntax error. Parameter repeted."));
		}
		if (which_one != tex_COLOR_OK)
		{
			textures[which_one] = mlx_xpm_file_to_image(
					get_game_init(), new_set[which_one], NULL, NULL);
		}
		++i;
	}
	return (OK);
}

/* defines the which_one variable and scrolls the new_set[i] string to the
** beginning of the texture path. we can lose the original ptr because
** the string has been allocated with the cantalloc() function, so it will
** automatically be freed by cantalloc_clean() at the end of the code */
static t_texture	define_which(char **line_from_set)
{
	int which_one;

	while (**line_from_set == ' ')
		*line_from_set += 1;
	if (cub_strcmp(*line_from_set, "NO ") == 0)
		which_one = tex_GET_NORTH;
	else if (cub_strcmp(*line_from_set, "SO ") == 0)
		which_one = tex_GET_SOUTH;
	else if (cub_strcmp(*line_from_set, "WE ") == 0)
		which_one = tex_GET_WEST;
	else if (cub_strcmp(*line_from_set, "EA ") == 0)
		which_one = tex_GET_EAST;
	else if (cub_strcmp(*line_from_set, "F ") == 0
		|| cub_strcmp(*line_from_set, "C ") == 0)
		which_one = get_color(*line_from_set);
	else
		which_one = tex_ERROR;
	while (**line_from_set != ' ')
		*line_from_set += 1;
	return (which_one);
}


static void	free_textures(void *textures[5])
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		//free(textures[i]); // or destroy_something_something ?
		textures[i] = 0;
		++i;
	}
}

int	new_textures(char **new_set)
{
	if (texture_handler(new_set, tex_UPDATE) != NULL)
		return (NOT_OK);
	return (OK);
}

