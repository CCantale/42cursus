/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:32 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/27 23:53:14 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# include "common.h"
# include <stdio.h>

int		phi_atoi(char *info);
size_t	phi_time(t_ime *relativity);
void	phi_sleep(t_ime *relativity, size_t be_right_back);

#endif
