/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:08:10 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 21:25:02 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_handler.h"

void	*game_handler(void *ptr, t_game option)
{
	static void	*init;
	static void	*window;

	if (option == g_INIT)
		init = ptr;
	else if (option == g_WINDOW)
		window = ptr;
	else if (option == g_GET_INIT)
		return (init);
	else if (option == g_GET_WINDOW)
		return (window);
	return (NULL);
}

void	game_init(void	*init)
{
	game_handler(init, g_INIT);
}

void	window_init(void *window)
{
	game_handler(window, g_WINDOW);
}

void	*get_game_init(void)
{
	return (game_handler(NULL, g_GET_INIT));
}

void	*get_window(void)
{
	return (game_handler(NULL, g_GET_WINDOW));
}
