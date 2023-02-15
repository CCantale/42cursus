/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:18:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/15 18:27:04 by ccantale         ###   ########.fr       */
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

int	check_map(char **map, char *path)
{
	
	*map = open_and_read(path);
	if (!map)
		return (NOT_OK);

	//read
	//funcs
	
	return (OK);
}
