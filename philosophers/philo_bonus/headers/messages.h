/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:32 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/04 19:32:52 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# include <pthread.h>

# include "common.h"

size_t	phi_time(t_info *info);
void	phi_sleep(t_info *info, size_t be_right_back);

int		check_death(t_philo *philo);
void	actions(t_philo *philo, int action, size_t time);

#endif
