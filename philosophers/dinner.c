/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:25:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/06 13:07:03 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/dinner.h"

int	invite_friend(struct s_ophos *sophos)
{
	if (pthread_create(&sophos->who_am_I_really, NULL,
				(void *)(*routine), (void *)sophos) != 0)
		{
			printf("CULO\n");																		// QUI C'è un culo -Dan
			return (1);
		}
	return (0);
}

int	dinner(t_ime *relativity)
{
	int i;

	i = 0;
	while (i < relativity->how_many_men_make_a_crowd)
	{
		if (invite_friend(relativity->sophos + i) != 0)
		{
			wait_why_dont_we_use_one_fork_each(relativity);
			return (1);
		}
		++i;
	}
	//monitor();
	return (0);
}
