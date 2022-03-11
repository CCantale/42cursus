#include "so_long.h"

int	get_walls(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 72;
	game->out_block = mlx_xpm_file_to_image(game->init, "out_block.xpm", &x, &y);
	if (!game->out_block)
		return (0);
	return (1);
}

void get_xml(t_game *game)
{
	get_walls(game);
}
