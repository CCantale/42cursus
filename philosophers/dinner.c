/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:25:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/05 17:04:52 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/dinner.h"
																									#include <stdio.h>
int	invite_friend(t_ime *relativity, int i)
{
	if (pthread_create(&relativity->who_am_I_really[i], NULL,
				(void *)(*routine), (void *)&relativity->sophos[i]) != 0)
		{
			printf("CULO\n");																		// QUI C'è un culo -Dan
			return (1);
		}
//	pthread_detach(relativity->who_am_I_really[i]);
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
	//monitor();
	return (0);
}
