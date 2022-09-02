/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:48:43 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/02 18:14:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/quit.h"
void	join(t_ime *relativity)
{
	int	i;

	i = 0;
	while (i < relativity->how_many_men_make_a_crowd)
	{
		pthread_join(relativity->who_am_I_really[i], NULL);
		++i;
	}
}

void	wait_why_dont_we_use_one_fork_each(t_ime *relativity)
{
	int	i;

	join(relativity);
	i = 0;
	while (i < relativity->how_many_men_make_a_crowd)
	{
		pthread_mutex_destroy(relativity->forks + i);
		++i;
	}
	free(relativity->forks);
	free(relativity->sophos);
	free(relativity->who_am_I_really);
}
