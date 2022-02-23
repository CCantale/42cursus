/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:42:17 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/23 16:42:20 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char **ft_check_walls(char **map)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (map[0][len])
	{
		if (map[0][len] != '1')
			return (NULL);
		++len;
	}
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (NULL);
		if (map[i][len - 1] != '1')
			return (NULL);
		++i;
	}
	j = 0;
	while (map[i - 1][j])
		if (map[i - 1][j++] != '1')
			return (NULL);
	return (map);
}


static char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1)
		return (s2);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	while (s1)
	{
		join[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2)
	{
		join[i + j] = s2[j];
		++j;
	}
	join[i + j] = 0;
	free(s1);
	return (join);
}


static char	*ft_read_map(int fd)
{
	char	buffer[2048];
	char	*map;
	int		len;

	map = 0;
	len = read(fd, buffer, 2048);
	while (len)
	{
		map = ft_join(map, buffer);
		len = read(fd, buffer, 2048);
	}
	return (map);
}

static char	*ft_check_ber(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	return (ft_strnstr(filename, ".ber", len));
}

char	**ft_check_map(char *path)
{
	char	**map;
	char	*str;
	int		fd;

	if (!ft_check_ber(path))
		return(NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = ft_read_map(fd);
	if (!ft_strchr(str, 'C') || !ft_strchr(str, 'E') || !ft_strchr(str, 'P'))
	{
		free(map);
		return (NULL);
	}
	map = ft_split(str, '\n');
	free(str);
	if (!map)
	{
		ft_printf("Map error");
		return (NULL);
	}
	return (ft_check_walls(map));
}
	
