/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:25:55 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/28 01:44:01 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STTRUCTS_H

typedef struct	s_info
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_per_philo;
	int				meals_eaten;
	unsigned int	start_timestamp;
	sem_t			fork;
	sem_t			death;
	sem_t			messages;
}					t_info;
