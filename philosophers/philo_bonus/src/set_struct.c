/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:57:04 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/29 15:53:32 by ccantale         ###   ########.fr       */
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
	if (set_maphores(info))
		return (1);
	/*info->someone_died = 0;
	if (inform_forks(info))
		return (1);
	if (set_table(info))
		return (1);*/
	return (0);
}

int	set_maphores(t_info *info)
{
	sem_unlink("forks");
	sem_unlink("death");
	sem_unlink("messages");
	info->death = sem_open("death", O_CREAT | O_EXCL, 0600, 1);
	if (info->death == SEM_FAILED)
		return (1);
	info->messages = sem_open("messages", O_CREAT | O_EXCL, 0600, 1);
	if (info->messages == SEM_FAILED)
	{
		sem_close(info->death);
		return (1);
	}
	info->forks = sem_open("forks",
			O_CREAT | O_EXCL, 0600, info->nbr_of_philo);
	{
		sem_close(info->death);
		sem_close(info->messages);
		return (1);
	}
	return (0);
}
