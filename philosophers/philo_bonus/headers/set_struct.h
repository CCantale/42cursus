/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:55:30 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/29 19:15:41 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_STRUCT_H
# define SET_STRUCT_H

# include "common.h"

void	*phi_calloc(size_t count, size_t size);
int		phi_atoi(char *info);
int		mistake(char *advice);

int		set_maphores(t_info *info);
void 	set_philo(t_philo *philo, t_info *info);

#endif
