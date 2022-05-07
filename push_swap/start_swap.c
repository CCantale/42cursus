/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:17:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/05/07 14:18:18 by ccantale         ###   ########.fr       */
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

int	*find_swap(t_struct *s, int start)
{
	int	i;
	int	j;
	int	*new_stack;

	new_stack = malloc(sizeof(int) * s->slots);
	i = start;
	while (i < s->slots)
	{
		new_stack[i] = s->stack_a[start + i];
		++i;
	}
	j = 0;
	while (j < start)
	{
		new_stack[start + i] = s->stack_a[j];
		++j;
	}
	free(s->stack_a);
	print_swap(s, start);
	return (new_stack);
}

/* scrolls stack_a up to the starting point */

void	shift_swap(t_struct *s, int start)
{
	s->stack_a = find_swap(s, start);
}

/* puts longest increasing sequence in stack_b, right to left */

void	tfihs_swap(t_struct *s, int start)
{
	s->stack_a = find_swap(s, start);
}

/* puts longest increasing sequence in stack_b, left to right */

void	start_swap(t_struct *s, int start)
{
	if (start > 0)
		shift_swap(s, start);
	else
	{
		start *= -1;
		tfihs_swap(s, start);
	}
}	

/* Write comment here... */
