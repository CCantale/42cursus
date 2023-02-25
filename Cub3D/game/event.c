/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:48:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 03:52:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../keycodes.h"
#include "../cantalloc/cantalloc.h"

void	render_background(void);
/* end of declarations */

void	event(int key)
{
	if (key == ESC_KEY)
	{
		cantalloc_clean();
		exit(0);
	}
	else
	{
		render_background();
	}
}
