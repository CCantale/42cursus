/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inform.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:59:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/14 23:40:27 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/inform.h"

int	inform(t_ime *relativity, char **info)
{
	relativity->how_many_men_make_a_crowd = phi_atoi(info[1]);
	relativity->what_is_death = phi_atoi(info[2]);
	relativity->we_are_what_we_eat = phi_atoi(info[3]);
	relativity->is_life_a_dream = phi_atoi(info[4]);
	if (relativity->how_many_men_make_a_crowd == -1
			|| relativity->what_is_death == -1
			|| relativity->we_are_what_we_eat == -1
			|| relativity->is_life_a_dream == -1)
		return (1);
	//relativity->sophos = inform_philosophers(relativity);
	return (0);
}
