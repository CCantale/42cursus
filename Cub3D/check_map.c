/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:18:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/19 22:37:43 by ccantale         ###   ########.fr       */
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

int	*check_type_identifier(char *str, int option)
{
	static int	identifiers[5];
	int			i;

	i = 0;
	if (option == e_INIT)
		while (i < 5)
			identifiers[i++] = 0;
	else if (option == e_CHECK)
	{
		if (cub_strcmp(str, "NO ") == 0)
			++identifiers[e_NO];
		else if (cub_strcmp(str, "SO ") == 0)
			++identifiers[e_SO];
		else if (cub_strcmp(str, "WE ") == 0)
			++identifiers[e_WE];
		else if (cub_strcmp(str, "EA ") == 0)
			++identifiers[e_EA];
		else if (cub_strcmp(str, "F ") == 0)
			++identifiers[e_F];
		else
			identifiers[0] = 42;
	}
	else if (option == GET_IDENTIFIERS)
		return (identifiers);
	return (NULL);
}
	
// get next line 

int	check_map(char *path)
{	
	char	*map;
	int		i;

	map = open_and_read(path);
	if (!map)
		return (NOT_OK);
	init_map(map);
	if (check_borders(get_map()) == NOT_OK)
		return (NOT_OK);
	return (OK);
}
