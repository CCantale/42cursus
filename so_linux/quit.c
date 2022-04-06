#include "so_long.h"

int	quit(t_game *game)
{
	int		i;
	char	**map;
	
	map = game->map;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
	exit(0);
	return (0);
}
