/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:10:38 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/05 20:21:08 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../global_headers/common.h"
# include "../global_headers/game_info.h"
# include "../global_headers/game.h"
# include "../minilibX/mlx.h"

void			render_background(void);
double const	*get_walls(void);

#endif
