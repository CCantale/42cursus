/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:15:27 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/05 16:42:19 by ccantale         ###   ########.fr       */
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
	int				what_is_death;
	int				we_are_what_we_eat;
	int				is_life_a_dream;
	int				how_much_is_enough;
	pthread_mutex_t	*forks;
	struct s_ophos	*sophos;
	pthread_t		*who_am_I_really;
}					t_ime;

typedef struct		s_ophos
{
	int				seat_nbr;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals;
	pthread_mutex_t	pen;
	t_ime			*relativity;
}					t_philo;

#endif
