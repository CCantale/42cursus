/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:15:27 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/14 21:28:38 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct s_ophos;

typedef enum		e_action
{
	ACTION
}					t_action;

typedef struct		s_pace
{
	int				how_many_men_make_a_crowd;
	int				what_is_death;
	int				we_are_what_we_eat;
	int				is_life_a_dream;
	int				how_much_is_enough;
	int				*forks;
	struct sophos	*sophos;
}					t_ime;

typedef struct		s_ophos
{
	t_ime			*relativity;
}					t_philo;

#endif
