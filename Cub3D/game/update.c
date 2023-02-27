/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:27:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 17:04:00 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

void	move_up(void);

int	update(void)
{
	bool	do_nothing;

	do_nothing = false;
	if (get_key(k_LEFT) == true)
		rotate(r_LEFT);
	else if (get_key(k_RIGHT) == true)
		rotate(r_RIGHT);
	else if (get_key(k_W) == true)
		move_up();
	else
		do_nothing = true;
	time_start();
	if (do_nothing == false)
		render();
	return (0);
}
