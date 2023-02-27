/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:48:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 02:48:01 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global_headers/keycodes.h"
#include "../cantalloc/cantalloc.h"
#include "../movements/rotate.h"

void	render_background(void);
void	render(void);
void	rotate(t_rotation direction);
/* end of declarations */

void	event(int key)
{
	if (key == ESC_KEY)
	{
		cantalloc_clean();
		exit(0);
	}
	else if (key == LEFT_KEY)
		rotate(r_LEFT);
	else if (key == RIGHT_KEY)
		rotate(r_RIGHT);
	render();
}
