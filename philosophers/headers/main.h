/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:13:49 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/06 18:00:55 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "common_knowledge.h"
# include <stdio.h>

int		mistake(char *advice);
int		phi_atoi(char *info);
size_t	phi_time(void);
int		inform(t_ime *relativity, char **info, int argc);
int		dinner(t_ime *relativity);

#endif
