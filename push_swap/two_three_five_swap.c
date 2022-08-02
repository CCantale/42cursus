/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_three_five_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:35:57 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/02 22:03:14 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	two_swap(t_struct *s)
{
	if (s->stack_a[0] < s->stack_a[1])
		return ;
	else
		ft_printf("sa");
}

/* only two nbrs to sort. Easy peasy lemon_swap */

void	three_swap(t_struct *s)
{
	if (s->stack_a[0] < s->stack_a[1] && s->stack_a[1] > s->stack_a[2]
		&& s->stack_a[0] < s->stack_a[2])
	{
		ra_swap(s->stack_a);
		sa_swap(s->stack_a);
		ft_printf("ra\nsa\n");
	}
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] < s->stack_a[2]
		&& s->stack_a[0] < s->stack_a[2])
	{
		rra_swap(s->stack_a);
		sa_swap(s->stack_a);
		ft_printf("rra\nsa\n");
	}
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] > s->stack_a[2]
		&& s->stack_a[0] > s->stack_a[2])
	{
		sa_swap(s->stack_a);
		ft_printf("sa\n");
	}
	end_swap(s);
}

/* cases considered:
** 
**   132
**   213
**   321 
**
** then end_swap is used to scroll stack_a 
** and to push nbrs back in it, if needed
*/

void	five_swap(t_struct *s)
{
	int	i;
	int	j;

	s->stack_b = malloc(sizeof(int) * s->slots - 3);
	s->slots_b = s->slots - 3;
	i = s->slots - 3;
	while (i > 0)
	{
		ft_printf("pb\n");
		s->stack_b[1] = s->stack_b[0];
		s->stack_b[0] = s->stack_a[0];
		j = 0;
		while (j < s->slots - 1)
		{
			s->stack_a[j] = s->stack_a[j + 1];
			++j;
		}
		--s->slots;
		--i;
	}
	three_swap(s);
}

/* pushes the first one or two nbrs in stack_b in order to leave only
** three nbrs in stack_a. then sorts stack_a using three_swap() */
