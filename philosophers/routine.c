/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:51:35 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/01 17:08:09 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/routine.h"
																						#include <stdio.h>

int	sleep_think(struct s_ophos *sophos)
{
	//check_dead
	msg(sophos, SLEEPING);
	//check_dead
	phi_sleep(sophos->relativity->is_life_a_dream);
	//check_dead
	msg(sophos, THINKING);
	return (0);
}

int	eat(struct s_ophos *sophos)
{
	//check_dead
	//piglia il tempo
	msg(sophos, EATING);
	phi_sleep(sophos->relativity->we_are_what_we_eat);
	sophos->meals++;
	pthread_mutex_unlock(sophos->left_fork);
	if (sophos->relativity->how_many_men_make_a_crowd > 1)
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
	//if (check_dead)
	//	return (1);
	pthread_mutex_lock(sophos->left_fork);
	msg(sophos, TAKEN);
	//check_dead
	if (sophos->relativity->how_many_men_make_a_crowd > 1)
		pthread_mutex_lock(sophos->right_fork);
	msg(sophos, TAKEN);
	return (0);
}


void	*routine(struct s_ophos *sophos)
{
														//printf("Hello, I'm number %d!\n", sophos->seat_nbr);
	while (1)
	{
		if (take_forks(sophos) || eat(sophos) || sleep_think(sophos))
			break ;
	}
	return (NULL);
}
