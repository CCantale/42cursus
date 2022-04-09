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
			if (game->map[i][j] == 'N')
				mlx_put_image_to_window(game->init, game->win,
					game->enemy, j * 64, i * 64);

			++j;
		}
		++i;
	}
}

void	put_sprites(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->init, game->win,
			game->player, j * 64, i * 64 + 8);
		game->player_x = j;
		game->player_y = i;
		if (game->map[i + 1][j] == '1')
			put_whatever(game, i + 1, j);
	}
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->init, game->win,
			game->o_door, j * 64, i * 64 + 8);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->init, game->win,
			game->turner, j * 64, i * 64 + 8);
	if (game->map[i][j] == ' ' && game->start != 0)
	{
		mlx_put_image_to_window(game->init, game->win,
			game->background, j * 64, i * 64);
		if (game->map[i - 1][j] == '1' || game->map[i - 1][j] == 'E')
			put_whatever(game, i - 1, j);
		if (game->map[i + 1][j] == '1')
			put_whatever(game, i + 1, j);
	}
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
	if (i && game->start != 0 && game->map[i][j] == '1'
		&& (game->map[i - 1][j] == '1' || game->map[i - 1][j] == 'E'))
		put_whatever(game, i - 1, j);
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
	mlx_put_image_to_window(game->init, game->win, game->black,
			0, game->map_y * 64 + 8);
	mlx_string_put(game->init, game->win, 10, game->map_y *64 + 8,
			0xFFFFFF, ft_itoa(game->steps));
}

int	update(t_game *game)
{
	if (game->start == 0)
	{
		put_start(game);
		game->start = 1;
	}
	if (game->animation != 0)
		play_animation(game);
	return (1);
}
