/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:57:04 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/02 14:52:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/set_struct.h"

int	set_struct(t_info *info, t_philo *philo, char **argv, int argc)
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
	if (set_maphores(info) || set_maforks(info))
		return (1);
	info->start_timestamp = 0;
	info->philo = philo;
	set_philo(philo, info);
	return (0);
}

int	set_maphores(t_info *info)
{
	sem_unlink("death");
	sem_unlink("messages");
	sem_unlink("stop");
	info->death = sem_open("death", O_CREAT | O_EXCL, 0600, 1);
	if (info->death == SEM_FAILED)
		return (1);
	info->messages = sem_open("messages", O_CREAT | O_EXCL, 0600, 1);
	if (info->messages == SEM_FAILED)
	{
		sem_close(info->death);
		return (1);
	}
	info->stop = sem_open("stop", O_CREAT | O_EXCL, 0600, 0);
	if (info->stop == SEM_FAILED)
	{
		sem_close(info->death);
		sem_close(info->messages);
		return (1);
	}
	return (0);
}

int	set_maforks(t_info *info)
{
	sem_unlink("forks");
	info->forks = sem_open("forks",
			O_CREAT | O_EXCL, 0600, info->nbr_of_philo);
	if (info->forks == SEM_FAILED)
	{
		sem_close(info->death);
		sem_close(info->messages);
		sem_close(info->stop);
		return (1);
	}
	return (0);
}

void set_philo(t_philo *philo, t_info *info)
{
	philo->index = 0;
	philo->someone_died = NO;
	philo->meals = 0;
	philo->last_meal = philo->info->start_timestamp;	
	philo->info = info;
}
