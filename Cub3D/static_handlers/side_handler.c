/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:20:48 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 03:06:53 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../global_headers/common.h"
# include "../global_headers/game_info.h"

static int	*side_handler(int option)
{
	static int	side[WINDOW_WIDTH];
	static int	i;

	if (option == X)
		side[i++] = X;
	else if (option == Y)
		side[i++] = Y;
	else if (option == 3)
		return (side);
	if (i >= WINDOW_WIDTH)
		i = 0;
	return (NULL);
}

void	add_side(int option)
{
	side_handler(option);
}

int	*get_side(void)
{
	return (side_handler(3));
}
