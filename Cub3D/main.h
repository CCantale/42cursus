/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:12:21 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 15:37:04 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "common.h"
# include "cantalloc/cantalloc.h"
# include "static_handlers/map.h"

int	error_msg(char *msg);
int	check_map(char *path);

#endif


