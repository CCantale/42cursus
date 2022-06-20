/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:17:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/06/20 17:18:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	*noob_swap(t_struct *s, int *lis, int new_slots)
{
	int	i;
	int	j;
	int	k;
	int	*noob;
																						int	p;

																						ft_printf("\n\nSTACK_A = ");
																						p = 0;
																						while (p < s->slots)
																						{
																							ft_printf("%d ", s->stack_a[p]);
																							++p;
																						}

	noob = malloc(sizeof(int) * new_slots);
	j = lis[-1] - 1;
	k = 0;
	i = s->slots - 1;
	while (i >= 0)
	{
		if (j >= 0 && s->stack_a[i] == lis[j])
			--j;
		else
		{
			noob[k] = s->stack_a[i];
			++k;
		}
		--i;
	}
	s->slots_b = new_slots;
	return (noob);
}

/* pushes nonLISers in stack_b 
** (new_b -> newbe -> noob) */

int	*rem_swap(t_struct *s, int *lis)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < s->slots)
	{
		if (s->stack_a[i] == lis[j])
		{
			ft_printf("ra\n");
			++j;
		}
		else
		{
			ft_printf("pb\n");
		}
		++i;
	}
	return (noob_swap(s, lis, s->slots - lis[-1]));
}

/* pushes whats not in the LIS to stack_b 
** and prints out the required operations */

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
	int	start;

	i = 1;
	start = 0;
	while (start < s->slots)
	{
		if (s->stack_a[start] == lis[i])
			++i;
		else
			break ;
		++start;
	}
	print_swap(s, start);
	s->stack_b = rem_swap(s, lis + 1);
	free(s->stack_a);
	s->stack_a = lis + 1;
	s->slots = lis[0];
																						ft_printf("\n\nslots  a - b = %d - %d\n\n", s->slots, s->slots_b);
																						int	p;

																						ft_printf("\n\nSTACK_A = ");
																						p = 0;
																						while (p < s->slots)
																						{
																							ft_printf("%d ", s->stack_a[p]);
																							++p;
																						}
																						ft_printf("\n\nSTACK_B = ");
																						p = 0;
																						while (p < s->slots_b)
																						{
																							ft_printf("%d ", s->stack_b[p]);
																							++p;
																						}
}	

/* scrolls stack_a to the fist nonLIS nbr,
** then pushes all nonLIS nbrs in stack_b */
