/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:05:09 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/07 16:43:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/messages.h"

void	msg(struct s_ophos *sophos, int	action)
{
	size_t time;

	pthread_mutex_lock(&sophos->relativity->pen);
	time = phi_time(sophos->relativity);
	if (action == TAKEN)
		printf("%zu	%d has taken a fork\n", time, sophos->seat_nbr + 1);
	if (action == EATING)
		printf("%zu	%d is eating\n", time, sophos->seat_nbr + 1);
	if (action == SLEEPING)
		printf("%zu	%d is sleeping\n", time, sophos->seat_nbr + 1);
	if (action == THINKING)
		printf("%zu	%d is thinking\n", time, sophos->seat_nbr + 1);
	if (action == DIED)
		printf("%zu	%d died\n", time, sophos->seat_nbr + 1);
	if (action == FULL)
		printf("%zu	%d is full\n", time, sophos->seat_nbr + 1);
	pthread_mutex_unlock(&sophos->relativity->pen);
}

int	mistake(char *advice)
{
	printf("\n\"It looks like something's wrong here, am I right?\n It's ok,"
			" don't beat yourself up too much about it.\n%s\"\n\n", advice);
	return (-1);
}

/* philosophers tend to talk a bit much... */
