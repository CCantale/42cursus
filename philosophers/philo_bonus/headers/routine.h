/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:52:05 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/02 22:31:21 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include <unistd.h>
# include <pthread.h>
# include "common.h"

void	msg(t_info *info, int action);
size_t	phi_time(t_info *info);

void	*monitor(t_philo *philo);
int		init_thread(t_philo *philo);
int		check_death(t_philo *philo);

#endif
