/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:17:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/05/27 17:56:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	print_swap(t_struct *s, int start)
{
	int	i;

													ft_printf("start = %d\n slots = %d\n", start, s->slots);
	if (start < s->slots / 2)
	{
		i = 0;
		while (i < start)
		{
			ft_printf("ra\n");
			++i;
		}
	}
	else
	{
		i = start;
		while (i < s->slots)
		{
			ft_printf("rra\n");
			++i;
		}
	}
}

/* prints ra or rra depending on the starting point */

int	*shift_swap(t_struct *s, int lis)
{

}

/* scrolls stack_a up to the starting point */

void	start_swap(t_struct *s, int	*lis)
{
	shift_swap(s, start);
}	

/* Write comment here... */
