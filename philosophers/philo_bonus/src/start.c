/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:52:43 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/30 17:56:45 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/start.h"

int	start(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_of_philo)
	{
		info->philo->index++;
		info->philo->pid = fork();
		if (info->philo->pid == -1)
			return (i);
		if (info->philo->pid == 0)
		{
			routine(info->philo);
			break ;
		}
		else
			info->sons[i - 1] = info->philo->pid;
		++i;
		usleep(90);
	}
	//sem_wait(info->stop);
	sleep(10);
	return (0);
}
