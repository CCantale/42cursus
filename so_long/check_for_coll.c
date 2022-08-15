/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_coll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:19:33 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/03 12:26:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_coll(char **map, int map_y)
{
	int	i;
	int	j;

	i = 1;
	while (i < map_y)
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}
