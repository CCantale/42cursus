/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:27:25 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 08:28:12 by ccantale         ###   ########.fr       */
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

#endif
