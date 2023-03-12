/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:19:52 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/12 19:20:54 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIDE_H
# define SIDE_H

typedef enum e_side
{
	s_ADD_SIDE,
	s_GET_SIDE,
	s_NORTH,
	s_SOUTH,
	s_EAST,
	s_WEST
}	t_side;

void	add_ray_side(int axis_hit, int position);
t_side	*get_side(void);

#endif
