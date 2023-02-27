/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:12:21 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/26 22:31:26 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "global_headers/common.h"
# include "cantalloc/cantalloc.h"
# include "global_headers/map.h"
# include "minilibX/mlx.h"
# include "global_headers/game_info.h"
# include "global_headers/game.h"

int		error_msg(char *msg);
int		check_map(char *path);
void	render_background(void);
void	render(void);
int		update(void);
int		event(int key);

#endif


