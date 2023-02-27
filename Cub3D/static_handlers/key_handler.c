/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:00:16 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 08:39:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_handler.h"

static bool	key_handler(t_key key, t_key option)
{
	static bool	keys[6] = { false, false, false, false, false, false };

	if (option == k_SWITCH)
	{
		if (keys[key] == false)
			keys[key] = true;
		else
			keys[key] = false;
	}
	else if (option == k_GET)
	{
		return (keys[key]);
	}
	return (true);
}

void	switch_key(t_key key)
{
	key_handler(key, k_SWITCH);
}

bool	get_key(t_key key)
{
	return (key_handler(key, k_GET));
}
