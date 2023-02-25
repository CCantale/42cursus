/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 07:12:15 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 13:07:00 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_handler.h"

int	player_handler(int x, int y, t_player option)
{
	static int	pos_x;
	static int	pos_y;
	static int	dir_x;
	static int	dir_y;

	if (option == p_EDIT_POS)
	{
		pos_x = x;
		pos_y = y;
	}
	else if (option == p_EDIT_DIR)
	{
		dir_x = x;
		dir_y = y;
	}
	else if (option == p_GET_POSX)
		return (pos_x);
	else if (option == p_GET_POSY)
		return (pos_y);
	else if (option == p_GET_DIRX)
		return (dir_x);
	else if (option == p_GET_DIRY)
		return (dir_y);
	return (OK);
}

int	get_player_x(void)
{
	player_handler(0, 0, p_GET_POSX);
}

int	get_player_y(void)
{
	player_handler(0, 0, p_GET_POSY);
}

int	get_player_dir
