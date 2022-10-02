/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:33 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/03 00:02:03 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/routine.h"

void	routine(t_philo *philo)
{
	init_thread(philo);
	//usleep(100);
	while (1)
	{
		sem_wait(philo->info->forks);
		if (check_death(philo))
			break ;
		msg(philo->info, TAKEN);
		sem_wait(philo->info->forks);
		if (check_death(philo))
			break ;
		msg(philo->info, TAKEN);
		if (check_death(philo))
			break ;
		msg(philo->info, EATING);
		usleep(philo->info->time_to_eat);
		philo->meals++;
		if (philo->meals == philo->info->meals_per_philo)
		{
			if (check_death(philo))	//mettere 'stammerda denttro a msg() e vaffanculo
				break ;
			msg(philo->info, FULL);
		}
		philo->last_meal = phi_time(philo->info);
		sem_post(philo->info->forks);
		sem_post(philo->info->forks);
		if (check_death(philo))
			break ;
		msg(philo->info, SLEEPING);
		usleep(philo->info->time_to_sleep);
		if (check_death(philo))
			break ;
		msg(philo->info, THINKING);
	}
	sem_post(philo->info->stop);
	pthread_join(philo->thread, NULL);
}

void	*monitor(t_philo *philo)
{
	pthread_mutex_init(philo->death_mutex, NULL);
	sem_wait(philo->info->death);
	pthread_mutex_lock(philo->death_mutex);
	philo->someone_died = YES;
	pthread_mutex_unlock(philo->death_mutex);
	pthread_mutex_destroy(philo->death_mutex);
	return (NULL);
}

int	init_thread(t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL,
			(void *)(*monitor), (void *)philo) != 0)
	{
		return (1);
	}
	return (0);
}

int	check_death(t_philo *philo)
{
	if (phi_time(philo->info) - philo->last_meal < philo->info->time_to_die)
	{
		sem_post(philo->info->death);
		return (1);
	}
	pthread_mutex_lock(philo->death_mutex);
	if (philo->someone_died == YES)
	{
		pthread_mutex_unlock(philo->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->death_mutex);
	return (0);
}
