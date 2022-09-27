/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:21:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/27 19:22:50 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fork_actions.h"

void	wait_for_k(pthread_mutex_t *fork_mutex, int *fork)
{
	while (1)
	{
		pthread_mutex_lock(fork_mutex);
		if (*fork == 0)
		{
			*fork = 1;
			pthread_mutex_unlock(fork_mutex);
			break ;
		}
		pthread_mutex_unlock(fork_mutex);
	}
}

void	put_forks_down(struct s_ophos *sophos)
{
	pthread_mutex_lock(sophos->left_mutex);
	*sophos->left_fork = 0;
	pthread_mutex_unlock(sophos->left_mutex);
	pthread_mutex_lock(sophos->right_mutex);
	*sophos->right_fork = 0;
	pthread_mutex_unlock(sophos->right_mutex);
}
