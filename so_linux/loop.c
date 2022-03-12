#include "so_long.h"

void	put_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == ' ')
				mlx_put_image_to_window(game->init, game->win,
					game->background, j * 64, i * 64);
			++j;
		}
		++i;
	}
}

void	put_sprites(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->init, game->win,
			game->player, j * 64, i * 64 + 8);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->init, game->win,
			game->o_door, j * 64, i * 64 + 8);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->init, game->win,
			game->turner, j * 64, i * 64 + 8);
}

void	put_whatever(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1' && i)
	{
		if (game->map[i - 1][j] == 'P')
			mlx_put_image_to_window(game->init, game->win,
				game->s_block, j * 64, i * 64);
		else if (game->map[i - 1][j] == 'C')
			mlx_put_image_to_window(game->init, game->win,
				game->t_block, j * 64, i * 64);
		else
			mlx_put_image_to_window(game->init, game->win,
				game->out_block, j * 64, i * 64);
	}
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->init, game->win,
			game->out_block, j * 64, i * 64);
	else
		put_sprites(game, i, j);
}

void	put_start(t_game *game)
{
	int	i;
	int	j;

	put_background(game);
	i = game->map_y - 1;
	while (i >= 0)
	{
		j = 0;
		while (game->map[i][j])
		{
			put_whatever(game, i, j);
			++j;
		}
		--i;
	}
}

int	update(t_game *game)
{
	if (game->start == 0)
	{
		put_start(game);
		game->start = 1;
	}
	if (game->changes)
	{
		game->changes = 0;
	}
	return (1);
}
