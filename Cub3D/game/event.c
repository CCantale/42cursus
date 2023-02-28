/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:48:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/28 19:38:52 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global_headers/keycodes.h"
#include "../global_headers/key.h"
#include "../cantalloc/cantalloc.h"

void	push(int key)
{
	if (key == ESC_KEY)
	{
		cantalloc_clean();
		exit(0);
	}
	if (key == LEFT_KEY)
		press_key(k_LEFT);
	if (key == RIGHT_KEY)
		press_key(k_RIGHT);
	if (key == W_KEY)
		press_key(k_W);
}

void	pull(int key)
{
	if (key == LEFT_KEY)
		release_key(k_LEFT);
	if (key == RIGHT_KEY)
		release_key(k_RIGHT);
	if (key == W_KEY)
		release_key(k_W);
}
