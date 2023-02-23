/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:23:43 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 17:05:09 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_handler.h"

static int	define_which(char **line_from_set);
static int	update_textures(char **new_set, void *textures[6]);
static void	free_textures(void *textures[6]);
/* end of declarations */

/*
** textures[0] = north
** textures[1] = south
** textures[2] = west
** textures[3] = east
** textures[4] = floor
** textures[5] = 0
*/
void	*texture_handler(char **new_set, int option)
{
	static void	*textures[6];
	static short	init_var;

	if (init_var == 0)
	{
		while (init_var < 6)
		{
			textures[init_var] = NULL;
			++init_var;
		}
	}
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

static int	update_textures(char **new_set, void *textures[6])
{
	size_t	i;
	int	which_one;

	i = 0;
	while (i < 5)
	{
		which_one = define_which(&new_set[i]);
		if (which_one == tex_ERROR)
		{
			free_textures(textures);
			return (error_msg("Syntax error. Unknown parameter."));
		}
		if (textures[which_one] != NULL)
		{
			free_textures(textures);
			return (error_msg("Syntax error. Parameter repeted."));
		}
		textures[which_one] = *new_set; // funzione che fa le texture
		++i;
	}
	return (OK);
}

/* defines the which_one variable and scrolls the new_set[i] string to the
** beginning of the texture path. we can lose the original ptr because
** the string has been allocated with the cantalloc() function, so it will
** automatically be freed by cantalloc_clean() at the end of the code or
** in emergency_exit() in case anything goes wrong */
static int	define_which(char **line_from_set)
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
	else if (cub_strcmp(*line_from_set, "F ") == 0)
		which_one = tex_GET_FLOOR;
	else
		which_one = tex_ERROR;
	while (**line_from_set != ' ')
		*line_from_set += 1;
	return (which_one);
}


static void	free_textures(void *textures[6])
{
	int	i;

	i = 0;
	while (textures[i])
	{
		free(textures[i]); // or destroy_something_something ?
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

