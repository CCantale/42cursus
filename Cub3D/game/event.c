/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:48:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/19 01:31:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

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
	if (key == S_KEY)
		press_key(k_S);
	if (key == A_KEY)
		press_key(k_A);
	if (key == D_KEY)
		press_key(k_D);
}

void	pull(int key)
{
	if (key == LEFT_KEY)
		release_key(k_LEFT);
	if (key == RIGHT_KEY)
		release_key(k_RIGHT);
	if (key == W_KEY)
		release_key(k_W);
	if (key == S_KEY)
		release_key(k_S);
	if (key == A_KEY)
		release_key(k_A);
	if (key == D_KEY)
		release_key(k_D);
}
