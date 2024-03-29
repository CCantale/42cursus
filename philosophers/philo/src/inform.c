/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inform.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:59:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/27 18:02:58 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/inform.h"

int	inform_forks(t_ime *relativity)
{
	int	i;

	relativity->forks = phi_calloc(relativity->how_many_men_make_a_crowd,
			sizeof(int));
	relativity->fork_mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t)
			* relativity->how_many_men_make_a_crowd);
	if (!relativity->fork_mutex)
		return (mistake(" This time it's really not your fault.\n"
				" Not all mutexes come out with a malloc."));
	i = 0;
	while (i < relativity->how_many_men_make_a_crowd)
	{
		pthread_mutex_init(relativity->fork_mutex + i, NULL);
		++i;
	}
	return (0);
}

int	set_table(t_ime *relativity)
{
	int	i;

	relativity->sophos = phi_calloc(relativity->how_many_men_make_a_crowd,
			sizeof(t_philo));
	if (!relativity->sophos)
		return (mistake(" This time it's really not your fault.\n Not all of"
				" us will answer when you calloc them."));
	i = -1;
	while (++i < relativity->how_many_men_make_a_crowd)
	{
		relativity->sophos[i].seat_nbr = i;
		relativity->sophos[i].left_fork = relativity->forks + i;
		relativity->sophos[i].right_fork = relativity->forks + i + 1;
		relativity->sophos[i].left_mutex = relativity->fork_mutex + i;
		relativity->sophos[i].right_mutex = relativity->fork_mutex + i + 1;
		if (i == relativity->how_many_men_make_a_crowd - 1)
		{
			relativity->sophos[i].right_fork = relativity->forks;
			relativity->sophos[i].right_mutex = relativity->fork_mutex;
		}
		relativity->sophos[i].meals = 0;
		relativity->sophos[i].relativity = relativity;
	}
	relativity->full_stomacs = 0;
	return (0);
}

int	inform(t_ime *relativity, char **info, int argc)
{
	relativity->how_many_men_make_a_crowd = phi_atoi(info[1]);
	relativity->what_is_death = phi_atoi(info[2]);
	relativity->we_are_what_we_eat = phi_atoi(info[3]);
	relativity->is_life_a_dream = phi_atoi(info[4]);
	if (relativity->how_many_men_make_a_crowd == -1
		|| relativity->we_are_what_we_eat == -1
		|| relativity->is_life_a_dream == -1)
		return (1);
	if (relativity->is_life_a_dream == -1)
		return (1);
	if (argc == 6)
		relativity->how_much_is_enough = phi_atoi(info[5]);
	else
		relativity->how_much_is_enough = -1;
	if (argc == 6 && relativity->how_much_is_enough == -1)
		return (1);
	pthread_mutex_init(&relativity->death_mutex, NULL);
	pthread_mutex_init(&relativity->pen, NULL);
	pthread_mutex_init(&relativity->full_mutex, NULL);
	relativity->someone_died = 0;
	if (inform_forks(relativity))
		return (1);
	if (set_table(relativity))
		return (1);
	return (0);
}

/* how_many_men_make_a_crowd	=		nbr of philosophers
** what_is_death				=		time to die
** we_are_what_we_eat			=		time to eat
** is_life_a_dream				=		time to sleep
** how_much_is_enough			=		nbr of times each philosopher must eat
*/
