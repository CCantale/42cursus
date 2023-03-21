/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:34:58 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 20:10:17 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_handler.h"

static int	define_which(char **line_from_set);
static int	update_textures(char **new_set, t_image textures[TEX_NUMBER]);
static void	destroy_textures(t_image textures[TEX_NUMBER]);
/* end of declarations */

t_image	*texture_handler(char **new_set, int option)
{
	static t_image	textures[TEX_NUMBER];
	int				i;

	if (option == tex_UPDATE)
	{
		if (!new_set || update_textures(new_set, textures) == NOT_OK)
			return (textures);
		i = 0;
		while (i < TEX_NUMBER)
		{
			textures[i].addr = mlx_get_data_addr(textures[i].image,
					&textures[i].bits_per_pixel, &textures[i].line_size,
					&textures[i].endian);
			++i;
		}
	}
	else
	{
		return (&textures[option]);
	}
	return (NULL);
}

static int	update_textures(char **new_set, t_image textures[TEX_NUMBER])
{
	size_t	i;
	int		which_one;

	i = 0;
	while (i < 6)
	{
		which_one = define_which(&new_set[i]);
		if (which_one == tex_ERROR)
		{
			destroy_textures(textures);
			return (error_msg("Syntax error. Wrong or missing parameter."));
		}
		if (textures[which_one].image != NULL
			|| which_one == tex_COLOR_REPEATED)
		{
			destroy_textures(textures);
			return (error_msg("Syntax error. Parameter repeted."));
		}
		if (which_one != tex_COLOR_OK)
			textures[which_one].image = mlx_xpm_file_to_image(get_game_init(),
					new_set[i], &textures[which_one].width,
					&textures[which_one].height);
		++i;
	}
	return (OK);
}

/* defines the which_one variable and scrolls the new_set[i] string to the
** beginning of the texture path. we can lose the original ptr because
** the string has been allocated with the cantalloc() function, so it will
** automatically be freed by cantalloc_clean() at the end of the code */
static int	define_which(char **line_from_set)
{
	int	which_one;

	while (**line_from_set == ' ')
		*line_from_set += 1;
	if (cub_strcmp(*line_from_set, "NO ") == 0)
		which_one = s_NORTH;
	else if (cub_strcmp(*line_from_set, "SO ") == 0)
		which_one = s_SOUTH;
	else if (cub_strcmp(*line_from_set, "WE ") == 0)
		which_one = s_WEST;
	else if (cub_strcmp(*line_from_set, "EA ") == 0)
		which_one = s_EAST;
	else if (cub_strcmp(*line_from_set, "F ") == 0
		|| cub_strcmp(*line_from_set, "C ") == 0)
		which_one = get_color(*line_from_set);
	else
		which_one = tex_ERROR;
	while (**line_from_set != ' ')
		*line_from_set += 1;
	while (**line_from_set == ' ')
		*line_from_set += 1;
	return (which_one);
}

static void	destroy_textures(t_image textures[TEX_NUMBER])
{
	size_t	i;

	i = 0;
	while (i < TEX_NUMBER)
	{
		if (textures[i].image)
			mlx_destroy_image(get_game_init(), textures[i].image);
		++i;
	}
}

int	new_textures(char **new_set)
{
	if (texture_handler(new_set, tex_UPDATE) != NULL)
		return (NOT_OK);
	return (OK);
}
