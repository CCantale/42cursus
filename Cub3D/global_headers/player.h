/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:47:08 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/20 16:44:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

/* Size of the field of vision. It's a value between 0.1 and 1 */
# define FOV_SIZE			0.66

# define SPEED				3
# define ROTATION_SPEED		2

void		init_player(void);
void		init_camera_plan(void);
void		update_player_pos(double x, double y);
void		update_player_dir(double x, double y);
void		update_camera_plan(double x, double y);
double		get_player_x(void);
double		get_player_y(void);
double		get_player_dirx(void);
double		get_player_diry(void);
double		get_camera_x(void);
double		get_camera_y(void);

#endif
