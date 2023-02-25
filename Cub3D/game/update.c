/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:27:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 17:19:14 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <sys/time.h> // ricorda che tutta 'sta roba è illegale
# include <unistd.h>


size_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

int	update(void)
{
	static size_t	frame_time = 1000000 / 60;
	size_t			start;
	size_t			end;

	start = get_time();
	// update
/*	static size_t	count = 0;
	printf("%lu\n", count);
	++count; */
	end = get_time();
	while (end - start < frame_time)
	{
		usleep(1000);
		end = get_time();
	}
	return (0);
}
