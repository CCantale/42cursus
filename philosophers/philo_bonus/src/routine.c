/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:33 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/05 18:13:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/routine.h"

void	routine_init(t_philo *philo)
{
	pthread_mutex_init(&philo->death_mutex, NULL);
	init_thread(philo);
	philo->last_meal = phi_time(philo->info);
	routine(philo);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	pthread_join(philo->thread, NULL);
	pthread_mutex_destroy(&philo->death_mutex);
	sem_post(philo->info->full);
}

void	routine(t_philo *philo)
{
	while (1)
	{
		sem_wait(philo->info->forks);
		if (msg(philo->info, TAKEN))
			break ;
		sem_wait(philo->info->forks);
		if (msg(philo->info, TAKEN))
			break ;
		if (msg(philo->info, EATING))
			break ;
		phi_sleep(philo->info, philo->info->time_to_eat);
		philo->meals++;
		if (philo->meals == philo->info->meals_per_philo
				&& msg(philo->info, FULL))
			break ;
		if (msg(philo->info, NO_PRINT))
			break;
		philo->last_meal = phi_time(philo->info);
		sem_post(philo->info->forks);
		sem_post(philo->info->forks);
		if (msg(philo->info, SLEEPING))
			break ;
		phi_sleep(philo->info, philo->info->time_to_sleep);
		if (msg(philo->info, THINKING))
			break ;
	}
}

void	*monitor(t_philo *philo)
{
	sem_wait(philo->info->death);
	sem_post(philo->info->death);
	pthread_mutex_lock(&philo->death_mutex);
	philo->someone_died = YES;
	pthread_mutex_unlock(&philo->death_mutex);
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
