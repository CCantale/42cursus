/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:48:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/26 18:18:53 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global_headers/keycodes.h"
#include "../cantalloc/cantalloc.h"

void	render_background(void);
void	render(void);
/* end of declarations */

void	event(int key)
{
	static short flag;

	if (key == ESC_KEY)
	{
		cantalloc_clean();
		exit(0);
	}
	else if (flag == 0)
	{
		render_background();
		render();
		flag = 1;
	}
}
