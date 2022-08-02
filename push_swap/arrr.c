/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:18:01 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/02 21:18:45 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	r_swap(int steps_a, int steps_b, int dir)
{
	int	i;

	i = 0;
	while (i < steps_a)
	{
		if (dir == 0)
			ft_printf("ra\n");
		if (dir == 1)
			ft_printf("rra\n");
		++i;
	}
	i = 0;
	while (i < steps_b)
	{
		if (dir == 0)
			ft_printf("rrb\n");
		if (dir == 1)
			ft_printf("rb\n");
		++i;
	}
}

/* prints ra, rra, rb and rrb accordingly to the case.
** 
** dir:
** 0 = ra and rrb
** 1 = rra and rb
*/

void	arrr_swap(int steps_a, int steps_b, int dir)
{
	int	i;

	i = 0;
	while (i < small_swap(steps_a, steps_b))
	{
		if (dir == 0)
			ft_printf("rr\n");
		if (dir == 1)
			ft_printf("rrr\n");
		++i;
	}
	while (i < big_swap(steps_a, steps_b))
	{
		if (dir == 0 && steps_a > steps_b)
			ft_printf("ra\n");
		if (dir == 0 && steps_a < steps_b)
			ft_printf("rb\n");
		if (dir == 1 && steps_a > steps_b)
			ft_printf("rra\n");
		if (dir == 1 && steps_a < steps_b)
			ft_printf("rrb\n");
		++i;
	}
}

/* prints rr, rrr, ra, rra, rb and rrb accordingly to the case.
** it only treats the case in which the two stacks are to be
** scrolled in the same direction 
**
** dir:
** 0 = we're scrolling RIGHT to LEFT
** 1 = we're scrolling LEFT to RIGHT
*/
