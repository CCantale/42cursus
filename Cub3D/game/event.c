/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:48:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/26 21:02:51 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global_headers/keycodes.h"
#include "../cantalloc/cantalloc.h"

typedef enum e_rotation
{
	r_LEFT,
	r_RIGHT
}	t_rotation;

void	render_background(void);
void	render(void);
void	rotate(t_rotation direction);

/* end of declarations */

void	event(int key)
{
	static short flag;

	if (key == ESC_KEY)
	{
		cantalloc_clean();
		exit(0);
	}
	if (flag == 0)
	{
		render_background();
		flag = 1;
	}
	if (key == LEFT_KEY)
		rotate(r_LEFT);
	else if (key == RIGHT_KEY)
		rotate(r_RIGHT);
	render();
}
