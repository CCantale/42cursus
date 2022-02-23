/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:42:38 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/23 16:43:03 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_init(t_game game, char **map)
{
	if (!map)
	{
		ft_printf("Error\nMap check failed\n");
		return (0);
	}
	if (!game.init)
		return (0);
	return(1);
}

int	ft_get_key(int key, void *game)
{
	if (key == KEY_W)
		write(1, "ok!\n", 4);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nInsert one map\n"));
	game.init = mlx_init();
	if(!game.init)
		return (ft_printf("Error\ngame doesn't init\n"));
	game.win = mlx_new_window(game.init, 500, 500, GAME_NAME);
	if (!game.win)
		return (ft_printf("Error\nwindow doesn't init\n"));
	if (ft_map_init(game, ft_check_map(argv[1])))
	{
		mlx_key_hook(game.win, ft_get_key, &game);
//		mlx_loop_hook();
		mlx_loop(game.init);
//		ft_colse();
	}
	return (0);
}
