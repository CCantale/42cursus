/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:20:15 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/26 21:07:41 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_handler.h"

static size_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

static size_t	time_handler(t_time option)
{
	//static size_t	frame_rate = 1000000 / 60;
	static size_t	start;

	if (option == t_START)
	{
		start = get_time();
	}
	if (option == t_DELTA)
	{
		return (get_time() - start);
	}
	return (0);
}

void	time_start(void)
{
	time_handler(t_START);
}

size_t	get_delta_time(void)
{
	return (time_handler(t_DELTA));
}

