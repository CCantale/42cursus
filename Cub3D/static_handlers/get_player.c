/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:39:59 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 17:13:34 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_handler.h"

double	player_handler(double x, double y, t_player option);
/* end of declarations */

double	get_player_x(void)
{
	return (player_handler(0, 0, p_GET_POSX));
}

double	get_player_y(void)
{
	return (player_handler(0, 0, p_GET_POSY));
}

double	get_player_dirx(void)
{
	return (player_handler(0, 0, p_GET_DIRX));
}

double	get_player_diry(void)
{
	return (player_handler(0, 0, p_GET_DIRY));
}
