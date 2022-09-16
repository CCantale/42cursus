/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitarianism.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:34:25 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/16 12:17:28 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utilitarianism.h"

size_t	phi_time(t_ime *relativity)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - relativity->start);
}

void	phi_sleep(t_ime *relativity, size_t be_right_back)
{
	size_t	end;

	end = phi_time(relativity) + be_right_back;
	usleep(be_right_back * 1000 - 10000);
	while (phi_time(relativity) < end)
		continue ;
}

void	*phi_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*map;

	map = (void *)malloc(count * size);
	if (!map)
	{
		mistake(" There are times when even a simple allocation goes\n wrong"
			" and there's not much you can do to prevent it.\n Be wise,"
			" look ahead and always smile at the future.\n"
			" It will smile back, that's for sure.");
		return (NULL);
	}
	i = 0;
	while (i < size * count)
	{
		*((char *)map + i) = 0;
		++i;
	}
	return (map);
}

int	phi_atoi(char *info)
{
	int					i;
	unsigned long long	result;

	result = 0;
	i = 0;
	if (info[i] == '-')
		return (mistake(" I think that you're being a bit too negative."
				" Ok, listen,\n from now on, I want ALL your arguments"
				" to be positive.\n Trust me, it's life changing!"));
	while (info[i])
	{
		if (info[i] >= '0' && info[i] <= '9')
		{
			result *= 10;
			result += info[i++] - '0';
		}
		else
			return (mistake(" Words are important, but not this time, I'm afra"
					"id.\n Remember that all reality is made of nothing bu"
					"t numbers.\n And so should be your arguments."));
	}
	if (result > 2147483647)
		return (mistake(" It's good to dream big, but this time here\n"
				" try and keep your arguments smaller."));
	return ((int)result);
}

/* a normal atoi, but it gives you advices in case there's something wrong */
