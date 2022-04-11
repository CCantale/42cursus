/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:53:38 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/11 15:53:41 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step(t_game *game)
{
	char	*s;

	s = ft_itoa(game->steps);
	mlx_put_image_to_window(game->init, game->win, game->black,
			0, game->map_y * 64 + 8);
	mlx_string_put(game->init, game->win, 10, game->map_y *64 + 8,
			0xFFFFFF, s);
	free(s);
}
