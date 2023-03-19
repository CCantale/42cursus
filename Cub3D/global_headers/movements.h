/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:27:25 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/19 01:32:39 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

typedef enum e_rotation
{
	r_LEFT,
	r_RIGHT
}	t_rotation;

void	rotate(t_rotation direction);
void	move_forward(void);
void	move_back(void);
void	move_left(void);
void	move_right(void);

#endif
