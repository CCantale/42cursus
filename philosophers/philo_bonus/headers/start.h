/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:33:38 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/04 17:41:07 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_H
# define START_H

# include <stdlib.h>
# include <unistd.h>
# include "common.h"

void	routine_init(t_philo *philo);
size_t	phi_time(t_info *info);

#endif
