/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inform.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:59:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/16 15:20:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/inform.h"

/*int	inform_philosophers(t_ime *relativity)
{
	// write your code here...
	return(0);
}
*/
int	inform(t_ime *relativity, char **info, int argc)
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
	if (argc == 6)
		relativity->how_much_is_enough = phi_atoi(info[5]);
	else
		relativity->how_much_is_enough = -1;
	if (argc == 6 && relativity->how_much_is_enough == -1)
		return (1);
	relativity->forks = phi_calloc(relativity->how_many_men_make_a_crowd,
			sizeof(int));
	//relativity->sophos = inform_philosophers(relativity);
	return (0);
}

/* how_many_men_make_a_crowd	=		nbr of philosophers
** what_is_death				=		time to die
** we_are_what_we_eat			=		time to eat
** is_life_a_dream				=		time to sleep
** how_much_is_enough			=		nbr of times each philosopher must eat
*/
