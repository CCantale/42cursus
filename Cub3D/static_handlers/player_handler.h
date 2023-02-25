/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:44:46 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 17:12:49 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HANDLER_H
# define PLAYER_HANDLER_H

# include "../global_headers/common.h"
# include "../global_headers/map.h"

typedef enum	e_player
{
	p_UPDATE_POS,
	p_UPDATE_DIR,
	p_GET_POSX,
	p_GET_POSY,
	p_GET_DIRX,
	p_GET_DIRY
}	t_player;

void	update_player_pos(double x, double y);
void	update_player_dir(double x, double y);

#endif
