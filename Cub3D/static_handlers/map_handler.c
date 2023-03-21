/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:23:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 21:21:06 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_handler.h"

static char	**mapcpy(char **new_map);
/* end of declarations */

static char	**map_handler(char **new_map, int option)
{
	static char	**map;

	if (option == m_UPDATE_MAP)
	{
		map = mapcpy(new_map);
		return (map);
	}
	else if (option == m_GET_MAP)
	{
		return (map);
	}
	return (NULL);
}

static char	**mapcpy(char **new_map)
{
	char	**copy;
	size_t	size;
	size_t	i;

	size = 0;
	while (new_map[size])
		++size;
	copy = ccantalloc(size + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = cantalloc_dup(new_map[i]);
		if (!copy[i])
		{
			cantalloc_clean();
			return (error_null("cantalloc_dup() error in mapcpy()"));
		}
		++i;
	}
	return (copy);
}

int	update_map(char **new_map)
{
	if (!new_map || map_handler(new_map, m_UPDATE_MAP) == NULL)
		return (NOT_OK);
	return (OK);
}

char const	**get_map(void)
{
	return ((char const **)map_handler(NULL, m_GET_MAP));
}

void	edit_map(double x, double y, char edit)
{
	if (edit == '0' || edit == '1')
		map_handler(NULL, m_GET_MAP)[(int)(y)][(int)(x)] = edit;
}
