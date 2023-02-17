/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:18:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/17 18:22:52 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

char	*open_and_read(char *path)
{
	int		fd;
	int		read_check;
	char	buffer[2];
	char	*ret;

	ret = NULL;
	fd = open(path, O_RDONLY);
	read_check = read(fd, buffer, 1);
	while (read_check == 1)
	{
		buffer[1] = 0;
		ret = cub_join(ret, buffer, true, false);
		read_check = read(fd, buffer, 1);
	}
	close(fd);
	return (ret);
}

int	check_textures(char *map)
{
	size_t	i;
	short	cardinal_points[4];

	i = 0;
	while (i < 4)
		cardinal_points[i++] = 0;
	i = 0;
	while (map[i])
	{
		if (i != 0 & map[i] != ' ')
			continue ;
		if (cub_strncmp(map + i, " NO "))
		{
			if (cardinal_points[0] == 1)
				return (NOT_OK);
			cardinal_points[0] = 1;
		}
		// gli altri punto cardinali
		++i;
	}
	i = 0;
	while (i < 4)
		if (cardinal_points[i++] == 0)
			return (NOT_OK);
	return (OK);
	// checcazzo, è lunga in culooooooo
	// bisogna trovare un altro sistema...
}

int	check_map(char **map, char *path)
{
	
	*map = open_and_read(path);
	if (!map || check_textures(*map) == NOT_OK || check_borders(*map) == NOT_OK)
		return (NOT_OK);
	return (OK);
}
