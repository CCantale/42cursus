/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:52:05 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/04 18:19:03 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include <unistd.h>
# include <pthread.h>
# include "common.h"

int		msg(t_info *info, int action);
size_t	phi_time(t_info *info);
void	phi_sleep(t_info *info, size_t be_right_back);

void	routine(t_philo *philo);
void	*monitor(t_philo *philo);
int		init_thread(t_philo *philo);
int		check_death(t_philo *philo);

#endif
