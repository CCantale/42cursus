/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:05:09 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/01 17:04:22 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/messages.h"

void	msg(struct s_ophos *sophos, int	action)
{
	pthread_mutex_lock(&sophos->pen);
	if (action == TAKEN)
		printf("%zu	%d has taken a fork\n", phi_time(), sophos->seat_nbr);
	if (action == EATING)
		printf("%zu	%d is eating\n", phi_time(), sophos->seat_nbr);
	if (action == SLEEPING)
		printf("%zu	%d is sleeping\n", phi_time(), sophos->seat_nbr);
	if (action == THINKING)
		printf("%zu	%d is thinking\n", phi_time(), sophos->seat_nbr);
	if (action == DIED)
		printf("%zu	%d died\n", phi_time(), sophos->seat_nbr);
	if (action == FULL)
		printf("%zu	%d is full\n", phi_time(), sophos->seat_nbr);
	pthread_mutex_unlock(&sophos->pen);
}

int	mistake(char *advice)
{
	printf("\n\"It looks like something's wrong here, am I right?\n It's ok,"
			" don't beat yourself up too much about it.\n%s\"\n\n", advice);
	return (-1);
}

/* philosophers tend to talk a bit much... */
