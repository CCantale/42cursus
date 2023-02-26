/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:27:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/26 19:23:47 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../global_headers/common.h"
# include <stdio.h>
# include <sys/time.h> // ricorda che tutta 'sta roba è illegale
# include <unistd.h>
							#include "../global_headers/game_info.h"
							#include "../global_headers/player.h"
							double	*get_walls(void);
							double	start_raycasting(size_t ray_nbr);


int	update(void)
{
	static size_t	frame_rate = 1000000 / 60;
	size_t			start;
	size_t			end;

	start = get_time();
	// update
	end = get_time();
	return (0);
}
