/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:27:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 03:51:02 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>


size_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

int	update(void)
{
	static size_t	frame_time = 1000000/60;
	size_t			start;
	size_t			delta;

	start = get_time();
	// update
	delta = get_time();
	while (delta - start < frame_time)
	{
		usleep(100);
		delta = get_time();
	}
	return (0);
}
