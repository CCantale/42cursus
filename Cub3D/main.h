/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:12:21 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 03:51:48 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "common.h"
# include "cantalloc/cantalloc.h"
# include "static_handlers/map.h"
# include "minilibX/mlx.h"
# include "game_info.h"
# include "static_handlers/game.h"

int	error_msg(char *msg);
int	check_map(char *path);
int	update(void);
int	event(int key);

#endif


