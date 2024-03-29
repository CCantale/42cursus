/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:42:17 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/16 12:16:47 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_check_walls(char **map, int map_y)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (map[0][len])
		if (map[0][len++] != '1')
			return (error_msg("Map's outline need be all walls"));
	i = 1;
	while (i < map_y)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (error_msg("Map need be rectangular"));
		if (map[i][0] != '1')
			return (error_msg("Map's outline need be all walls"));
		if (map[i][len - 1] != '1')
			return (error_msg("Map's outline need be all walls"));
		++i;
	}
	j = 0;
	while (map[i - 1][j])
		if (map[i - 1][j++] != '1')
			return (error_msg("Map's outline need be all walls"));
	return (map);
}

static char	*ft_join(char *s1, char *s2, int len2)
{
	int		len1;
	char	*join;

	if (!s1)
	{
		join = malloc(sizeof(char) * (len2 + 1));
		ft_strlcpy(join, s2, len2 + 1);
		return (join);
	}
	len1 = ft_strlen(s1);
	join = malloc(sizeof(char) * (len1 + len2 + 1));
	ft_strlcpy(join, s1, len1 + 1);
	ft_strlcpy(join + len1, s2, len2 + 1);
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
		map = ft_join(map, buffer, len);
		len = read(fd, buffer, 2048);
	}
	if (!map)
		map = ft_calloc(1, sizeof(char));
	return (map);
}

static void	get_map_info(t_game *game, char **map)
{
	int	i;

	game->map_x = (int)ft_strlen(map[0]);
	i = 0;
	while (map[i])
		++i;
	game->map_y = i;
	game->map = map;
	game->start = 0;
	game->animation = 0;
	game->time = 0;
	game->steps = 0;
}

char	**ft_check_map(t_game *game, char *path)
{
	char	**map;
	char	*str;
	int		fd;

	if (!check_name(path, ".ber"))
		return (error_msg("File extention need be .ber"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_msg("Couldn't open file"));
	str = ft_read_map(fd);
	if (!check_letters(str))
		return (error_msg("Only availeable characters: C, E, P, N, 0 and 1"));
	if (!ft_strchr(str, 'C') || !ft_strchr(str, 'E') || !ft_strchr(str, 'P'))
	{
		free(str);
		return (error_msg("Map need be properly filled in"));
	}
	map = split_nl(str);
	free(str);
	close(fd);
	if (!map)
		return (error_msg("ft_split failed to create the map"));
	get_map_info(game, map);
	return (ft_check_walls(map, game->map_y));
}
