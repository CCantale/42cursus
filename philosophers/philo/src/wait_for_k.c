/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_k.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:04:44 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/27 18:05:58 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

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
