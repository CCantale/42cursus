/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:18:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/14 21:45:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <fcntl.h>

char	*open_and_read(char *path)
{
	int		fd;
	int		read_check;
	char	*buffer;
	char	*ret;

	ret = NULL;
	fd = open(path, O_RDONLY);
	read_check = read(fd, buffer, 1);
	while (read_check)
	{
		ret = cub_join(ret, buffer, true, false);
		read_check = read(fd, buffer, 1);
	}
	close(path);
	return (ret);
}

int	check_map(char *path)
{
	char	*input;
	
	input = open_and_read(path);
	if (!input)
		return (NULL);

	//read
	//funcs
	
	//close
	close(fd);
	return (OK);
}
