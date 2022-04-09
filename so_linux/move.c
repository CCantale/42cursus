#include "so_long.h"

void	move_u(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] == 'N')
		quit(game);
	if (game->map[y - 1][x] != '1' && game->map[y - 1][x] != 'E')
	{
		if (game->map[y - 1][x] == 'C')
			game->animation = 1;
		game->map[y][x] = ' ';
		game->map[y - 1][x] = 'P';
		put_whatever(game, y, x);
		put_whatever(game, y - 1, x);
		if (game->animation == 1)
			play_animation(game);
	}
	if (game->map[y - 1][x] == 'E')
	{
		if (check_for_coll(game->map, game->map_y) == 0)
			quit(game);
	}
}

void	move_d(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] == 'N')
		quit(game);
	if (game->map[y + 1][x] != '1' && game->map[y + 1][x] != 'E')
	{
		if (game->map[y + 1][x] == 'C')
			game->animation = 1;
		game->map[y][x] = ' ';
		game->map[y + 1][x] = 'P';
		put_whatever(game, y, x);
		put_whatever(game, y + 1, x);
		if (game->animation == 1)
			play_animation(game);
	}
	if (game->map[y + 1][x] == 'E')
	{
		if (check_for_coll(game->map, game->map_y) == 0)
			quit(game);
	}
}

void	move_l(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] == 'N')
		quit(game);
	if (game->map[y][x - 1] != '1' && game->map[y][x - 1] != 'E')
	{
		if (game->map[y][x - 1] == 'C')
			game->animation = 1;
		game->map[y][x] = ' ';
		game->map[y][x - 1] = 'P';
		put_whatever(game, y, x);
		put_whatever(game, y, x - 1);
		if (game->animation == 1)
			play_animation(game);
	}
	if (game->map[y][x - 1] == 'E')
	{
		if (check_for_coll(game->map, game->map_y) == 0)
			quit(game);
	}
}

void	move_r(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] == 'N')
		quit(game);
	if (game->map[y][x + 1] != '1' && game->map[y][x + 1] != 'E')
	{
		if (game->map[y][x + 1] == 'C')
			game->animation = 1;
		game->map[y][x] = ' ';
		game->map[y][x + 1] = 'P';
		put_whatever(game, y, x);
		put_whatever(game, y, x + 1);
		if (game->animation == 1)
			play_animation(game);
	}
	if (game->map[y][x + 1] == 'E')
	{
		if (check_for_coll(game->map, game->map_y) == 0)
			quit(game);
	}
}

void	move(t_game *game, int key)
{
	if (game->animation == 0)
	{
		if (key == UP)
			move_u(game);
		if (key == DOWN)
			move_d(game);
		if (key == LEFT)
			move_l(game);
		if (key == RIGHT)
			move_r(game);
	}
}
