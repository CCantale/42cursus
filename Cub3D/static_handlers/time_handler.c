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

static double	get_time(void)
{
	struct timespec	tv;

	clock_gettime(CLOCK_MONOTONIC, &tv);
	return (((double)tv.tv_sec + (double)tv.tv_nsec / 1000000000));
}

static double	time_handler(t_time option)
{
	static double	time_at_start;
	static double	start;
	static double 	delta;
	double			time_right_now;

	if (option == t_START)
	{
		time_at_start = get_time();
		start = time_at_start / 10000;
		//printf("start %lu\n", start);
	}
	if (option == t_DELTA)
	{
		//printf("start %f\n", start);
		time_right_now = get_time() - time_at_start;
		delta = time_right_now - start;
		start = time_right_now;
		//printf("nowrt %f\ndelta %f\n\n", time_right_now, delta);
		//printf("nowrt %lu\n", get_time());
		//printf("nowrt %f\n", time_right_now);
	}
	if (option == t_GET_DELTA)
	{
		//printf("delta %f\n", delta);
		return (delta);
	}
	return (0);
}

void	time_start(void)
{
	time_handler(t_START);
}

void	calculate_delta_time(void)
{
	time_handler(t_DELTA);
}

double	get_delta_time(void)
{
	return (time_handler(t_GET_DELTA));
}
