/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:10:38 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/15 07:07:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include "../global_headers/common.h"
# include "../global_headers/game_info.h"
# include "../global_headers/game.h"
# include "../global_headers/side.h"
# include "../global_headers/player.h"
# include "../global_headers/texture.h"
# include "../minilibX/mlx.h"

void			render_background(void);
double const	*get_walls(void);
void			draw_pixel(int x, int y, int color);
void			render_static();

#endif
