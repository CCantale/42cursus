/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:27:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/02 20:06:41 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"
											#include <unistd.h>
											#include <stdio.h>

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
	if (do_nothing == false)
	{
		printf("renderer\n");
		render();
	}
	usleep(100000);
	return (0);
}
