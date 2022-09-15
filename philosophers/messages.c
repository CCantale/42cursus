/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:05:09 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/15 16:38:26 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/messages.h"

void	msg(struct s_ophos *sophos, int	action)
{
	size_t time;

	pthread_mutex_lock(&sophos->relativity->pen);
	pthread_mutex_lock(&sophos->relativity->death_mutex);
	if (sophos->relativity->someone_died == 1 && action != DIED)
	{
		pthread_mutex_unlock(&sophos->relativity->pen);
		pthread_mutex_unlock(&sophos->relativity->death_mutex);
		return ;
	}
	pthread_mutex_unlock(&sophos->relativity->death_mutex);
	time = phi_time(sophos->relativity);
	if (action == TAKEN)
		printf("\033[0;32m%zu\033[0m	%d has taken a fork\n", time, sophos->seat_nbr + 1);
	if (action == EATING)
		printf("\033[0;35m%zu\033[0m	%d is eating\n", time, sophos->seat_nbr + 1);
	if (action == SLEEPING)
		printf("\033[0;36m%zu\033[0m	%d is sleeping\n", time, sophos->seat_nbr + 1);
	if (action == THINKING)
		printf("\033[0;33m%zu\033[0m	%d is thinking\n", time, sophos->seat_nbr + 1);
	if (action == DIED)
	{
		phi_sleep(sophos->relativity, 10);
		printf("%zu	%d died\n", time, sophos->seat_nbr + 1);
	}
	if (action == FULL)
		printf("\033[0;37m%zu\033[0m	%d is full\n", time, sophos->seat_nbr + 1);
	pthread_mutex_unlock(&sophos->relativity->pen);
}

int	mistake(char *advice)
{
	printf("\n\"It looks like something's wrong here, am I right?\n It's ok,"
			" don't beat yourself up too much about it.\n%s\"\n\n", advice);
	return (-1);
}

/* philosophers tend to talk a bit much... */
