/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:18:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/17 12:13:21 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

static char	*open_and_read(char *path)
{
	int		fd;
	int		read_check;
	char	buffer[2];
	char	*ret;

	ret = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_null("File not found"));
	read_check = 1;
	while (read_check == 1)
	{
		read_check = read(fd, buffer, 1);
		buffer[1] = 0;
		ret = cub_join(ret, buffer, true, false);
		if (!ret)
			return (NULL);
	}
	close(fd);
	return (ret);
}

static int	check_valid_char(void)
{
	char const	**map = get_map();
	size_t		x;
	size_t		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'N'
					&& map[y][x] != 'S' && map[y][x] != 'E' && map[y][x] != 'W'
					&& map[y][x] != ' ')
			{
				return (error_msg("Not allowed characters in the map."));
			}
			++x;
		}
		++y;
	}
	return (OK);
}

static int	check_borders(void)
{
	char const	**map = get_map();
	size_t		x;
	size_t		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != ' '
					&& (y == 0 || x == 0 || !map[y][x + 1] || map[y + 1] == NULL
					|| map[y - 1][x] == ' ' || map[y + 1][x] == ' '
					|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
			{
				return (error_msg("Map should be surrounded by walls."));
			}
			++x;
		}
		++y;
	}
	return (OK);
}

static int	check_multiple_players(void)
{
	char const	**map = get_map();
	size_t		x;
	size_t		y;
	short		flag;

	flag = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (flag == 0)
					flag = 1;
				else
					return (error_msg("This is not a multiplayer game."));
			}
			++x;
		}
		++y;
	}
	return (OK);
}

int	check_map(char *path)
{	
	char	*input;

	input = open_and_read(path);
	if (!input)
		return (NOT_OK);
	if (static_handlers_init(cub_split(input)) == NOT_OK)
		return (NOT_OK);
	free(input);
	if (check_valid_char() == NOT_OK || check_borders() == NOT_OK
		|| check_multiple_players())
		return (NOT_OK);
	init_player();
	init_camera_plan();
	edit_map(get_player_x(), get_player_y(), '0');
	return (OK);
}
