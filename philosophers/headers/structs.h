/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:15:27 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/11 19:54:46 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct s_ophos;

typedef enum		e_action
{
	TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	FULL
}					t_action;

typedef struct		s_pace
{
	int				how_many_men_make_a_crowd;
	size_t			what_is_death;
	int				we_are_what_we_eat;
	int				is_life_a_dream;
	int				how_much_is_enough;
	size_t			start;
	pthread_mutex_t	death_mutex;
	int				someone_died;
	int				full_stomacs;
	pthread_mutex_t	*forks;
	pthread_mutex_t	pen;
	struct s_ophos	*sophos;
}					t_ime;

typedef struct		s_ophos
{
	int				seat_nbr;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals;
	size_t			last_meal;
	pthread_t		who_am_I_really;
	t_ime			*relativity;
}					t_philo;

#endif
