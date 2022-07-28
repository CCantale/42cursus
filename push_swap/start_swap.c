/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:17:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/28 17:37:51 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	comp_swap(int *lis, int lislots, int nbr)
{
	int	i;

	i = 0;
	while (i < lislots)
	{
		if (lis[i] == nbr)
			return (1);
		++i;
	}
	return (0);
}

/* checks if current nbr is in the LIS and returns 1 if so, 0 if not */

void	noob_swap(t_struct *s, int *lis, int start)
{
	int	i;
	int	j;
	int	k;

	s->stack_b = malloc(sizeof(int) * s->slots);
	i = start + 1;
	if (i == s->slots)
		i = 0;
	j = 1;
	k = 0;
	while (i != start)
	{
		if (j <= lis[-1] && s->stack_a[i] == lis[j])
		{
			++j;
		}
		else
		{
			s->stack_b[k] = s->stack_a[i];
			++s->slots_b;
			++k;
		}
		++i;
		if (i == s->slots)
			i = 0;
	}
}

/* pushes nonLISers in stack_b 
** (new_b -> newbe -> noob) */

void	rem_swap(t_struct *s, int *lis, int start)
{
	int	i;
	int	j;

	j = 1;
	ft_printf("ra\n");
	i = start + 1;
	if (i == s->slots)
		i = 0;
	while (i != start)
	{
		if (j <= lis[-1] && s->stack_a[i] == lis[j])
		{
			ft_printf("ra\n");
			++j;
		}
		else
		{
			ft_printf("pb\n");
		}
		++i;
		if (i == s->slots)
			i = 0;
	}
	noob_swap(s, lis, start);
	rev_swap(s->stack_b, s->slots_b);
}

/* pushes whats not in the LIS to stack_b 
** and prints out the required operations.
** No, I mean, yes, well, it certainly does
** so, only... in the opposite order */

void	print_swap(t_struct *s, int start)
{
	int	i;

	if (start <= s->slots / 2)
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

/* prints ra or rra depending on the starting point 
** this way we fake the scrolling of stack_a, while
** we're not actually doing it */

void	start_swap(t_struct *s, int	*lis)
{
	int	i;
	int	j;
	int	start;

	i = 1;
	start = 0;
	while (start < s->slots)
	{
		if (s->stack_a[start] == lis[i])
			break ;
		++start;
	}
	print_swap(s, start);
	rem_swap(s, lis + 1, start);
	i = 1;
	j = 0;
	while (i <= lis[0])
	{
		s->stack_a[j] = lis[i];
		++j;
		++i;
	}
	s->slots = lis[0];
	free(lis);
}	

/* scrolls stack_a to the fist nonLIS nbr,
** then keeps scrollin' and pushes all nonLIS 
** nbrs in stack_b. from now on, the nbr of 
** 'slots' of a stack does not represent the total 
** solts of the array, but the ones in use */
