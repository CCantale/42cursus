/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:20:15 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/02 20:03:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_handler.h"
#include <stdio.h>

static double	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static double	time_handler(t_time option)
{
	//static size_t	frame_rate = 1000000 / 12;
	static double	start;

	if (option == t_START)
	{
		start = get_time();
	}
	if (option == t_DELTA)
	{
		printf("START %f\nTIME %f\n", start, get_time());
		return (get_time() - start);
	}
	return (0);
}

void	time_start(void)
{
	time_handler(t_START);
}

double	get_delta_time(void)
{
	return (time_handler(t_DELTA));
}

