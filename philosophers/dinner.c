/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:25:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/29 15:35:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/dinner.h"
																									#include <stdio.h>

void	*routine(struct s_ophos *sophos)
{
	printf("Hello, I'm number %d!\n", sophos->seat_nbr);
	return (NULL);
}

int	invite_friend(t_ime *relativity, int i)
{
	pthread_t t;

	if (pthread_create(&t, NULL, (void *)(*routine), (void *)&relativity->sophos[i]) != 0)
		return (1);
	pthread_detach(t);
	relativity->who_am_I_really[i] = t;
	return (0);
}

int	dinner(t_ime *relativity)
{
	int i;

	relativity->who_am_I_really = malloc(sizeof(pthread_t)
			* relativity->how_many_men_make_a_crowd);
	i = 0;
	while (i < relativity->how_many_men_make_a_crowd)
	{
		if (invite_friend(relativity, i) != 0)
		{
			wait_why_dont_we_use_one_fork_each(relativity);
			return (1);
		}
		++i;
	}
	return (0);
}
