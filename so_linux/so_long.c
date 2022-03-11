/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:42:38 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/23 18:14:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_init(t_game *game, char **map)
{
	if (!map)
	{
		ft_printf("Error\nMap check failed\n");
		return (0);
	}
	game->map = map;
	if (!game->init)
		return (0);
	return(1);
}

int	ft_get_key(int key, t_game *game)
{
	if (!game)
		return (0);
	ft_printf("key %d\n", key);
	if (key == KEY_W)
		write(1, "ok!\n", 4);
	if (key == KEY_ESC)
		quit(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return ((int)error_int("Insert one map\n"));
	game.init = mlx_init();
	if(!game.init)
		return ((int)error_int("Game doesn't init\n"));
	if (ft_check_map(&game, argv[1]))
		game.win = mlx_new_window(game.init, game.map_x,
			game.map_y, GAME_NAME);
	else
		return (0);
	if (!game.win)
	{
		quit(&game);
		return ((int)error_int("Window doesn't init\n"));
	}
	get_xml(&game);
	mlx_key_hook(game.win, ft_get_key, &game);
	mlx_loop_hook(game.init, update, &game);
	mlx_loop(game.init);
	return (0);
}
