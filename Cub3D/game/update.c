/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:05:51 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/19 01:42:48 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

int	update(void)
{
	calculate_delta_time();
	if (get_key(k_LEFT) == true)
		rotate(r_LEFT);
	else if (get_key(k_RIGHT) == true)
		rotate(r_RIGHT);
	if (get_key(k_W) == true)
		move_forward();
	else if (get_key(k_S) == true)
		move_back();
	else if (get_key(k_A) == true)
		move_left();
	else if (get_key(k_D) == true)
		move_right();
	if (get_key(k_LEFT) || get_key(k_RIGHT)
			|| get_key(k_W) || get_key(k_S) || get_key(k_A) || get_key(k_D))
		render();
	return (0);
}
