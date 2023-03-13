/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:23:43 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/13 05:37:04 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_handler.h"
																#include <stdio.h>
																#include <fcntl.h>
																#include <unistd.h>
																#include <sys/mman.h>

static t_texture	define_which(char **line_from_set);
static int			update_textures(char **new_set, void *textures[5]);
static void			destroy_textures(void *textures[5]);
/* end of declarations */

/*
** textures[0] = north
** textures[1] = south
** textures[2] = west
** textures[3] = east
** textures[4] = 0
*/
char	*texture_handler(char **new_set, t_texture option)
{
	static void	*textures[5] = { NULL, NULL, NULL, NULL, NULL };
	static char	*addr[5] = { NULL, NULL, NULL, NULL, NULL };
	int			i;

	if (option == tex_UPDATE)
	{
		destroy_textures(textures);
		if (!new_set || update_textures(new_set, textures) == NOT_OK)
			return (*new_set);
		i = 0;
		while (i < 4)
		{
			addr[i] = mlx_get_data_addr(textures[i], NULL, NULL, NULL);
			++i;
		}
	}
	else if (option == tex_DESTROY)
	{
		destroy_textures(textures);
	}
	else
	{
		return (addr[option]);
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
			destroy_textures(textures);
			return (error_msg("Syntax error. Wrong or missing parameter."));
		}
		if (textures[which_one] != NULL || which_one == tex_COLOR_REPEATED)
		{
			destroy_textures(textures);
			return (error_msg("Syntax error. Parameter repeted."));
		}
		if (which_one != tex_COLOR_OK)
		{
			/*int fd, size;
			char	*ptr;
			fd = open(new_set[which_one], O_RDONLY);
			size = lseek(fd,0,SEEK_END);
			ptr = mmap(0,size,PROT_WRITE|PROT_READ,MAP_PRIVATE,fd,0);
			printf("%d %d %p\n", fd, size, ptr);
			close(fd);
  			munmap(ptr,size);*/
			void	*image;
			int	*w = NULL;
			int	*h = NULL;
			printf("%p %d %s %p\n",
					get_game_init(), which_one, new_set[which_one], textures[which_one]);
			image = mlx_xpm_file_to_image(get_game_init(), new_set[which_one], w, h);
			//textures[which_one] = mlx_xpm_file_to_image(
					//get_game_init(), new_set[which_one], w, h);
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
	while (**line_from_set == ' ')
		*line_from_set += 1;
	return (which_one);
}


static void	destroy_textures(void *textures[5])
{
	size_t	i;

	i = 0;
	while (textures[i])
	{
		mlx_destroy_image(get_game_init(), textures[i]);
		textures[i] = NULL;
		++i;
	}
}

int	new_textures(char **new_set)
{
	if (texture_handler(new_set, tex_UPDATE) != NULL)
		return (NOT_OK);
	return (OK);
}
