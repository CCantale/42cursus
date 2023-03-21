/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:10:38 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 17:00:30 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_PIXELS_H
# define DRAW_PIXELS_H

# include <math.h>
# include "../global_headers/common.h"
# include "../global_headers/game_info.h"
# include "../global_headers/game.h"
# include "../global_headers/side.h"
# include "../global_headers/player.h"
# include "../global_headers/texture.h"
# include "../global_headers/color.h"
# include "../global_headers/rendering.h"
# include "../minilibX/mlx.h"

double const	*get_walls(void);

#endif
