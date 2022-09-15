/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:32:33 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/16 01:25:14 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINNER_H
# define DINNER_H

# include "common_knowledge.h"

void	*routine(struct s_ophos *sophos);
size_t	phi_time(t_ime *relativity);
void	msg(struct s_ophos *sophos, int action);

#endif
