/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:04:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 09:50:20 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	game_loop(void);
/* end of declarations */

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (error_msg("One map required"));
	if (check_map(argv[1]) == NOT_OK || game_loop() == NOT_OK)
	{
		cantalloc_clean();
		return (1);
	}
	cantalloc_clean();
	return (0);
}

static int	quit(void)
{
	cantalloc_clean();
	exit(0);
	return (0);
}

static int	game_loop(void)
{
	game_init(mlx_init());
	if (!get_game_init())
		return (error_msg("Game doesn't init."));
	window_init(mlx_new_window(get_game_init(),
				WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME));
	if (!get_window())
	{
		return (error_msg("Window doesn't init."));
	}
	render();
	mlx_loop_hook(get_game_init(), update, NULL);
	mlx_hook(get_window(), 2, 1L << 0, press_any_key, NULL);
	mlx_hook(get_window(), 3, 1L << 1, press_any_key, NULL);
	mlx_hook(get_window(), 17, 1L << 17, quit, NULL);
	mlx_loop(get_game_init());
	return (OK);
}
