/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:57:04 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/28 01:15:23 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/set_struct.h"

int	set_struct(t_info *info, char **argv, int argc)
{
	info->nbr_of_philo = phi_atoi(argv[1]);
	info->time_to_die = phi_atoi(argv[2]);
	info->time_to_eat = phi_atoi(argv[3]);
	info->time_to_sleep = phi_atoi(argv[4]);
	if (info->nbr_of_philo == -1
		|| info->time_to_eat == -1
		|| info->time_to_sleep == -1)
		return (1);
	if (info->time_to_sleep == -1)
		return (1);
	if (argc == 6)
		info->meals_per_philo = phi_atoi(argv[5]);
	else
		info->meals_per_philo = -1;
	if (argc == 6 && info->meals_per_philo == -1)
		return (1);
	pthread_mutex_init(&info->death_mutex, NULL);
	pthread_mutex_init(&info->pen, NULL);
	pthread_mutex_init(&info->full_mutex, NULL);
	info->someone_died = 0;
	if (inform_forks(info))
		return (1);
	if (set_table(info))
		return (1);
	return (0);
}

int	inform_forks(t_ime *info)
{
	int	i;

	info->forks = phi_calloc(info->nbr_of_philo,
			sizeof(int));
	info->fork_mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t)
			* info->nbr_of_philo);
	if (!info->fork_mutex)
		return (mistake(" This time it's really not your fault.\n"
				" Not all mutexes come out with a malloc."));
	i = 0;
	while (i < info->nbr_of_philo)
	{
		pthread_mutex_init(info->fork_mutex + i, NULL);
		++i;
	}
	return (0);
}

int	set_table(t_ime *info)
{
	int	i;

	info->sophos = phi_calloc(info->nbr_of_philo,
			sizeof(t_philo));
	if (!info->sophos)
		return (mistake(" This time it's really not your fault.\n Not all of"
				" us will answer when you calloc them."));
	i = -1;
	while (++i < info->nbr_of_philo)
	{
		info->sophos[i].seat_nbr = i;
		info->sophos[i].left_fork = info->forks + i;
		info->sophos[i].right_fork = info->forks + i + 1;
		info->sophos[i].left_mutex = info->fork_mutex + i;
		info->sophos[i].right_mutex = info->fork_mutex + i + 1;
		if (i == info->nbr_of_philo - 1)
		{
			info->sophos[i].right_fork = info->forks;
			info->sophos[i].right_mutex = info->fork_mutex;
		}
		info->sophos[i].meals = 0;
		info->sophos[i].info = info;
	}
	info->full_stomacs = 0;
	return (0);
}
