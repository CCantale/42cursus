/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:05:09 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/04 19:42:53 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/messages.h"

int	msg(t_info *info, int action)
{
	size_t	time;
	int		dead;

	sem_wait(info->messages);
	time = phi_time(info);
	dead = check_death(info->philo);
	if (dead == DIED)
	{
		actions(info->philo, DIED, time);
		phi_sleep(info, 10);
		sem_post(info->messages);
		return (1);
	}
	else if (dead == YES)
	{
		sem_post(info->messages);
		return (1);
	}
		actions(info->philo, action, time);
	sem_post(info->messages);
	return (0);
}

void	actions(t_philo *philo, int action, size_t time)
{
	if (action == TAKEN)
		printf("\033[0;32m%zu\033[0m	%d has taken a fork\n",
			time, philo->index);
	else if (action == EATING)
		printf("\033[0;35m%zu\033[0m	%d is eating\n",
			time, philo->index);
	else if (action == SLEEPING)
		printf("\033[0;36m%zu\033[0m	%d is sleeping\n",
			time, philo->index);
	else if (action == THINKING)
		printf("\033[0;33m%zu\033[0m	%d is thinking\n",
			time, philo->index);
	else if (action == FULL)
		printf("\033[0;37m%zu\033[0m	%d is full\n",
				time, philo->index);
	else if (action == DIED)
		printf("%zu	%d died\n", time, philo->index);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->death_mutex);
	if (philo->someone_died == YES)
	{
		pthread_mutex_unlock(&philo->death_mutex);
		return (YES);
	}
	pthread_mutex_unlock(&philo->death_mutex);
	if (phi_time(philo->info) - philo->last_meal >= philo->info->time_to_die)
	{
		sem_post(philo->info->death);
		return (DIED);
	}
	return (NO);
}
