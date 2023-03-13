/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:20:15 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/13 14:02:34 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_handler.h"
#include <stdio.h>
#include <unistd.h>

static unsigned long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec);
}

static double	time_handler(t_time option)
{
	static unsigned long	start;
	unsigned long			time_from_start;

	if (option == t_START)
	{
		start = get_time();
	}
	if (option == t_DELTA)
	{
		time_from_start = get_time() - start;
		//printf("START %lu\nNOW %lu\nFROM_START %lu\n", start, get_time(), time_from_start);
		return ((double)(get_time() - start));
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
