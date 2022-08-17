/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:25:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/17 19:37:46 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dinner.h"

int	invite_friend(t_ime *relativity)
{
	pthread_t t;

	if (pthread_create(&t, NULL, &routine, relativity) != 0)
		return (1);
	pthread_detouch(t);
	return (0);
}

int	dinner(t_ime *relativity)
{
	int i;

	i = 0;
	while (i < relativity->how_many_men_make_a_crowd)
	{
		if (invite_friend(relativity) != 0)
		{
			quit(relativity);
			return (1);
		}
		++i;
	}
	return (0);
}
