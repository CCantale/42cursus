/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:51:35 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/06 18:56:15 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/routine.h"

int	sleep_think(struct s_ophos *sophos)
{
	if (sophos->relativity->death == 1)
		return (1);
	msg(sophos, SLEEPING);
	if (sophos->relativity->death == 1)
		return (1);
	phi_sleep(sophos->relativity, sophos->relativity->is_life_a_dream);
	if (sophos->relativity->death == 1)
		return (1);
	msg(sophos, THINKING);
	return (0);
}

int	eat(struct s_ophos *sophos)
{
	if (sophos->relativity->death == 1)
		return (1);
	msg(sophos, EATING);
	phi_sleep(sophos->relativity, sophos->relativity->we_are_what_we_eat);
	sophos->last_meal = phi_time(sophos->relativity);
	sophos->meals++;
	pthread_mutex_unlock(sophos->left_fork);
	pthread_mutex_unlock(sophos->right_fork);
	if (sophos->relativity->how_much_is_enough >= 0
			&& sophos->meals == sophos->relativity->how_much_is_enough)
	{
		msg(sophos, FULL);
		return (1);
	}
	return (0);
}



int	take_forks(struct s_ophos *sophos)
{
	if (sophos->relativity->death == 1)
		return (1);
	if (sophos->seat_nbr % 2 == 0)
		pthread_mutex_lock(sophos->left_fork);
	msg(sophos, TAKEN);
	if (sophos->relativity->death == 1)
		return (1);
	pthread_mutex_lock(sophos->right_fork);
	if (sophos->seat_nbr % 2 != 0)
		pthread_mutex_lock(sophos->left_fork);
	msg(sophos, TAKEN);
	return (0);
}


void	*routine(struct s_ophos *sophos)
{
	while (1)
	{
		if (take_forks(sophos) || eat(sophos) || sleep_think(sophos))
			break ;
	}
	return (NULL);
}
