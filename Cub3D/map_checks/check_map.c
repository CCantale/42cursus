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
		if (!ret)
			return (NULL);
		read_check = read(fd, buffer, 1);
	}
	close(fd);
	return (ret);
}

int	check_map(char *path)
{	
	char	*input;
	int	i;

	input = open_and_read(path);
	if (!input)
		return (NOT_OK);
	if (init_handlers(cub_split(input)) == NOT_OK)
		return (NOT_OK);
	if (check_borders(get_map()) == NOT_OK)
		return (NOT_OK);
	return (OK);
}
