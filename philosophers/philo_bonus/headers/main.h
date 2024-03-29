/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:57:00 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/30 16:57:29 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include "common.h"

int	set_sons(t_info *info);

int	set_struct(t_info *info, t_philo *philo, char **argv, int argc);
int	start(t_info *info);

#endif
