/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:51:35 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/30 00:33:58 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/routine.h"

int	sleep_think(struct s_ophos *sophos)
{
	//check_dead
	//msg_sleep
	//check_dead
	//phi_sleep()
	//check_dead
	//msg_think
	return (0);
}

int	eat(struct s_ophos *sophos)
{
	//check_dead
	//piglia il tempo
	//msg mangia
	//phi_sleep
	pthread_mutex_unlock(sophos->l_fork);
	if (sophos->relativity.how_many_men_make_a_crowd > 1)
		pthread_mutex_unlock(sophos->r_fork);
	return (0);
}



int	take_forks(struct s_ophos *sophos)
{
	//if (check_dead)
	//	return (1);
	pthread_mutex_lock(sophos->l_fork);
	//msg fork taken
	//check_dead
	if (sophos->relativity.how_many_men_make_a_crowd > 1)
		pthread_mutex_lock(sophos->r_fork);
	//msg fork taken
	return (0);
}


void	*routine(struct s_ophos *sophos)
{
														printf("Hello, I'm number %d!\n", sophos->seat_nbr);
	while (1)
	{
		if (take_forks(sophos) || eat(sophos) || sleep_think(sophos))
			break ;
	}
	return (NULL);
}
