/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:48:43 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/17 16:15:41 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/quit.h"

void	wait_why_dont_we_use_one_fork_each(t_ime *relativity)
{
	int	i;

	i = 0;
	while (i < relativity->how_many_men_make_a_crowd)
	{
		pthread_mutex_destroy(relativity->aut_aut + i);
		++i;
	}
	free(relativity->forks);
	free(relativity->sophos);
}
