
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:27:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/08 16:23:50 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

# include "../minilibX/mlx.h"
# include "../global_headers/game.h"
# include "../global_headers/keycodes.h"
void	move_up(void);
int		push(int key);
int		pull(int key);
# include "../global_headers/key.h"

int	update(void)
{
	static int	clocks;
	int			something_happened;

	if (clocks % 5 == 0)
	{
		something_happened = 1;
		if (get_key(k_LEFT) == true)
			rotate(r_LEFT);
		else if (get_key(k_RIGHT) == true)
			rotate(r_RIGHT);
		else if (get_key(k_W) == true)
			move_up();
		else
			something_happened = 0;
		if (something_happened == 1)
			render();
	}
	clocks++;
	time_start();

	return (0);
}
