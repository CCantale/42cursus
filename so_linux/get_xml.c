#include "so_long.h"

int	get_door(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 60;
	game->o_door = mlx_xpm_file_to_image(game->init,
		"sprites/o_door.xpm", &x, &y);
	if (!game->o_door)
		return (1);
	return (0);
}

int	get_player(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 56;
	game->player = mlx_xpm_file_to_image(game->init,
		"sprites/sandy5.xpm", &x, &y);
	if (!game->player)
		return (1);
	game->turner = mlx_xpm_file_to_image(game->init,
		"sprites/turner.xpm", &x, &y);
	if (!game->turner)
		return (1);
	game->enemy = mlx_xpm_file_to_image(game->init,
		"sprites/enemy.xpm", &x, &y);
	if (!game->l)
		return (1);
	return (0);
}

int	get_walls_and_background(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 72;
	game->out_block = mlx_xpm_file_to_image(game->init,
		"sprites/out_block.xpm", &x, &y);
	if (!game->out_block)
		return (1);
	game->t_block = mlx_xpm_file_to_image(game->init,
		"sprites/t_block.xpm", &x, &y);
	if (!game->t_block)
		return (1);
	game->s_block = mlx_xpm_file_to_image(game->init,
		"sprites/s_block.xpm", &x, &y);
	if (!game->s_block)
		return (1);
	game->background = mlx_xpm_file_to_image(game->init,
		"sprites/background.xpm", &x, &x);
	if (!game->background)
		return (1);
	return (0);
}

int	get_animation(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 72;
	game->flip[0] = mlx_xpm_file_to_image(game->init,
			"sprites/flip0.xpm", &x, &y);
	game->flip[1] = mlx_xpm_file_to_image(game->init,
			"sprites/flip1.xpm", &x, &y);
	game->flip[2] = mlx_xpm_file_to_image(game->init,
			"sprites/flip2.xpm", &x, &y);
	game->flip[3] = mlx_xpm_file_to_image(game->init,
			"sprites/flip3.xpm", &x, &y);
	game->flip[4] = mlx_xpm_file_to_image(game->init,
			"sprites/flip4.xpm", &x, &y);
	game->flip[5] = mlx_xpm_file_to_image(game->init,
			"sprites/flip5.xpm", &x, &y);
	return (0);
}

int	get_xml(t_game *game)
{
	int	i;

	i = 0;
	i += get_walls_and_background(game);
	i += get_player(game);
	i += get_door(game);
	i += get_animation(game);
	return (i);
}
