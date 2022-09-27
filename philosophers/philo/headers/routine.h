/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:00 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/27 18:05:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "common_knowledge.h"

void	msg(struct s_ophos *sophos, int action);
size_t	phi_time(t_ime *relativity);
void	wait_for_k(pthread_mutex_t *fork_mutex, int *fork);

#endif
