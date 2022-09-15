/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:25:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/11 19:58:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/dinner.h"

void	zio_maurizio(t_ime *relativity)
{
	int	i;

	i = 0;
	while (1)
	{
		if (phi_time(relativity) - relativity->sophos[i].last_meal >= relativity->what_is_death)
		{
			pthread_mutex_lock(&relativity->death_mutex);
			relativity->someone_died = 1;
			pthread_mutex_unlock(&relativity->death_mutex);
			msg(relativity->sophos + i, DIED);
			break ;
		}
		if (relativity->how_much_is_enough != -1
				&& relativity->full_stomacs >= relativity->how_much_is_enough)
		{
			pthread_mutex_lock(&relativity->death_mutex);
			relativity->someone_died = 1;
			pthread_mutex_unlock(&relativity->death_mutex);
			break ;
		}
		++i;
		if (i == relativity->how_many_men_make_a_crowd)
			i = 0;
	}
}

/* my uncle's a doctor, so I thoght I would have him check
** for the death of my friends here */ 

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
			return (1);
		++i;
	}
	zio_maurizio(relativity);
	return (0);
}
