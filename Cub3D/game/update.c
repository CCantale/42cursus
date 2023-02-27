/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:27:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 08:42:23 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

int	update(void)
{
	bool	do_nothing;

	time_start();
	do_nothing = false;
	if (get_key(k_LEFT) == true)
		rotate(r_LEFT);
	else if(get_key(k_RIGHT) == true)
		rotate(r_RIGHT);
	else
		do_nothing = true;
	if (do_nothing == false)
		render();
	return (0);
}
