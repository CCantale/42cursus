#include "so_long.h"

int	map_check_up(t_game *game)
{
	int	i;

	if (!game->prev_map)
		return (0);
	i = 0;
	while (game->map[i])
	{
		if (ft_strncmp(game->map[i], game->prev_map[i], game->map_x / 64))
			return (0);
		++i;
	}
	return (1);
}

void	put_walls(t_game *game)
{
	int	i;
	int	j;

	i = (game->map_y - 8) / 64;
	--i;
	while (i > -1)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->init, game->win,
					game->out_block, j * 64, i * 64);
			++j;
		}
		--i;
	}
}

int	update(t_game *game)
{
	if (!map_check_up(game))
	{
		put_walls(game);
		game->prev_map = game->map;
	}
	return (1);
}
