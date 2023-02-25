/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:47:08 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 17:10:25 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

void		init_player(void);
void		update_player_pos(double x, double y);
void		update_player_dir(double x, double y);
double		get_player_x(void);
double		get_player_y(void);
double		get_player_dirx(void);
double		get_player_diry(void);

#endif
