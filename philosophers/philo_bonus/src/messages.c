/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:05:09 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/02 23:54:20 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/messages.h"

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

void	msg(t_info *info, int action)
{
	size_t	time;

	sem_wait(info->messages);
	time = phi_time(info);
	actions(info->philo, action, time);
	sem_post(info->messages);
}
