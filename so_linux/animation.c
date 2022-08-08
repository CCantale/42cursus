/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:08:55 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/08 14:33:04 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	play_animation(t_game *game)
{
	if (game->time <= 700)
	{
		game->time++;
	}
	else if (game->animation > 0 && game->time > 700)
	{
		mlx_put_image_to_window(game->init, game->win,
			game->flip[game->animation - 1],
			game->player_x * 64, game->player_y * 64 + 8);
		game->animation++;
		if (game->animation > 6)
			game->animation = -1;
		game->time = 0;
	}
	else if (game->animation == -1)
	{
		put_whatever(game, game->player_y, game->player_x);
		game->animation = 0;
	}
}
