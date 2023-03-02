/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:00:16 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/02 19:18:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_handler.h"
												#include <stdio.h>

static bool	key_handler(t_key key, t_key option)
{
	static bool	keys[6] = { false, false, false, false, false, false };

	if (option == k_PRESS)
	{
		printf("true\n");
		keys[key] = true;
	}
	if (option == k_RELEASE)
	{
		printf("false\n");
		keys[key] = false;
	}
	if (option == k_GET)
	{
		return (keys[key]);
	}
	return (true);
}

void	press_key(t_key key)
{
	key_handler(key, k_PRESS);
}

void	release_key(t_key key)
{
	key_handler(key, k_RELEASE);
}

bool	get_key(t_key key)
{
	return (key_handler(key, k_GET));
}
