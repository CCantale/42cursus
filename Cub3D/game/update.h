/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:24:29 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/12 18:58:39 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "../global_headers/common.h"
# include "../global_headers/time.h"
# include "../global_headers/key.h"
# include "../global_headers/movements.h"
# include "../minilibX/mlx.h"
# include "../global_headers/game.h"
# include "../global_headers/keycodes.h"

void	move_up(void);
int		push(int key);
int		pull(int key);
void	render(void);

#endif
