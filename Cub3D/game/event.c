/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:48:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/04 19:44:38 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global_headers/keycodes.h"
#include "../global_headers/key.h"
#include "../cantalloc/cantalloc.h"
#include "../global_headers/movements.h"
#include <stdio.h>
/*void	move_up(void);
void	render(void);
#include "../global_headers/time.h"

void	push(int key)
{
	printf("PUSH\n");
	if (key == ESC_KEY)
	{
		cantalloc_clean();
		exit(0);
	}
	if (key == LEFT_KEY)
		rotate(r_LEFT);
	if (key == RIGHT_KEY)
		rotate(r_RIGHT);
	if (key == W_KEY)
		move_up();
	render();
	time_start();
}
*/

void	push(int key)
{
	printf("PUSH\n");
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
