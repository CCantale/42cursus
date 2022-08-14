/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inform.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:59:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/14 21:32:15 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/inform.h"

int	inform(t_ime *relativity, char **info)
{
	//t_philo	sophos;

	relativity->how_many_men_make_a_crowd = phi_atoi(info[1]);
	relativity->what_is_death = phi_atoi(info[2]);
	relativity->we_are_what_we_eat = phi_atoi(info[3]);
	relativity->is_life_a_dream = phi_atoi(info[4]);
	if (relativity->how_many_men_make_a_crowd == -1
			|| relativity->what_is_death == -1
			|| relativity->we_are_what_we_eat == -1
			|| relativity->is_life_a_dream == -1)
		return (1);
	return (0);
}
