/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:56:38 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/04 18:18:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.h"

size_t	phi_time(t_info *info)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - info->start_timestamp);
}

void	phi_sleep(t_info *info, size_t be_right_back)
{
	size_t	end;

	end = phi_time(info) + be_right_back;
	usleep(be_right_back * 1000 - 10000);
	while (phi_time(info) < end)
		continue ;
}

int	mistake(char *advice)
{
	printf("\n\"It looks like something's wrong here, am I right?\n It's ok,"
		" don't beat yourself up too much about it.\n%s\"\n\n", advice);
	return (-1);
}

void	*phi_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*map;

	map = malloc(count * size);
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
		map[i] = 0;
		++i;
	}
	return ((void *)map);
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
