/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:33 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/02 13:02:39 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/routine.h"

void	*monitor(t_philo *philo)
{
	sem_wait(philo->info->death);
	pthread_lock(philo->death_mutex);
	philo->someone_died = YES;
	pthread_unlock(philo->death_mutex);
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
`
void	routine(t_philo *philo)
{
	int	i;

	init_thread(philo);
	i = 0;
	while (i < 2)
	{
		printf("Hello World! I'm philosopher nbr %d :)\n", philo->index);
		usleep(1000);
		++i;
	}
//	while (take_forks(philo) && eat(philo) && sleep_think(philo))
//		continue ;
//	sem_post(philo->info->stop);
}
