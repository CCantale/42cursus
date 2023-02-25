/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:15:22 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 03:34:35 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HANDLER_H
# define GAME_HANDLER_H

# include "../common.h"

typedef enum	e_game
{
	g_INIT,
	g_WINDOW,
	g_GET_INIT,
	g_GET_WINDOW
}	t_game;

#endif
