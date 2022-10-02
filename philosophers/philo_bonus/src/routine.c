/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:33 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/02 15:05:46 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/routine.h"

void	*monitor(t_philo *philo)
{
	pthread_mutex_init(&philo->death_mutex, NULL);
	sem_wait(philo->info->death);
	pthread_lock(philo->death_mutex);
	philo->someone_died = YES;
	pthread_unlock(philo->death_mutex);
	pthread_mutex_destroy(&philo->death_mutex);
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

void	routine(t_philo *philo)
{
	int	i;

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
		if (meals == philo->info->meals_per_philo)
		{
			if (check_death(philo))
				break ;
			msg(philo->info, FULL);
		}
		philo->last_meal = phi_time(philo->info);
		sem_post(philo_->info->forks);
		sem_post(philo->info->forks);
		if (check_death(philo))
			break ;
		msg(philo->info, SLEEPING);
		usleep(philo->info->time_to_sleep);
		if (check_death(philo))
			break ;
		msg(philo->info, THINKING);
	}
}



		
//	while (take_forks(philo) && eat(philo) && sleep_think(philo))
//		continue ;
//	sem_post(philo->info->stop);
}
