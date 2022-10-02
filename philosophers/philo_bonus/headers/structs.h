/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:25:55 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/02 14:48:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_philo	t_philo;

enum
{
	YES,
	NO,
	TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	FULL	
};

typedef struct	s_info
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_per_philo;
	pid_t			*sons;
	unsigned int	start_timestamp;
	sem_t			*forks;
	sem_t			*death;
	sem_t			*messages;
	sem_t			*stop;
	t_philo			*philo;
}					t_info;

struct	s_philo
{
	int				index;
	int				someone_died;
	int				meals;
	int				last_meal;
	pid_t			pid;
	pthread_t		thread;
	pthread_mutex_t	death_mutex;
	t_info			*info;
};

#endif
