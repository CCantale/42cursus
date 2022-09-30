/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:33 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/30 16:58:16 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/routine.h"

void	routine(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("Hello World! I'm philosopher nbr %d :)\n", philo->index);
		usleep(1000);
	}
//	while (take_forks(philo) && eat(philo) && sleep_think(philo))
//		continue ;
}
