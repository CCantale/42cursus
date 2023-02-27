/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:48:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 08:48:51 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global_headers/keycodes.h"
#include "../global_headers/key.h"
#include "../cantalloc/cantalloc.h"

void	press_any_key(int key)
{
	if (key == ESC_KEY)
	{
		cantalloc_clean();
		exit(0);
	}
	else if (key == LEFT_KEY)
		switch_key(k_LEFT);
	else if (key == RIGHT_KEY)
		switch_key(k_RIGHT);
}
