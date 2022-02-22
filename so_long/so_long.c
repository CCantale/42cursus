#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Insert one map"));
	if (ft_check_map(argv[1]) && ft_map_init(game, argv[1]))
	{
		mlx_key_hook();
		mlx_loop_hook();
		mlx_loop();
		ft_colse();
	}
	return (0);
}
