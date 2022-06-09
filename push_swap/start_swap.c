/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:17:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/06/09 19:20:31 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	*rem_swap(int *stack_a, int *lis, int slots, int slots_b)
{
	int	i;
	int	j;
	int	k;
	int *new_a;

	new_a = malloc(sizeof(int) * slots - slots_b);
	k = 0;
	j = 0;
	i = 0;
	while (i < slots)
	{
		if (stack_a[i] == lis[j])
		{
			ft_printf("pb\n");
			++j;
		}
		else
		{
			new_a[k] = stack_a[i];
			++k;
			ft_printf("ra\n");
		}
		++i;
	}
	free(stack_a);
	return (new_a);
}

/* pushes the LIS to stack_b (actually just removes the LIS from stack_a) 
** and prints out the required operations */

void	print_swap(t_struct *s, int start)
{
	int	i;

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

int	*shift_swap(int *stack_a, int start, int slots)
{
	int	i;
	int	j;
	int	*scrolled_stack;

	scrolled_stack = malloc(sizeof(int) * slots + 1);
	i = start;
	j = 0;
	while (j < slots)
	{
		scrolled_stack[j] = stack_a[i];
		++i;
		++j;
		if (i >= slots)
			i = 0;
	}
	free(stack_a);
	return (scrolled_stack);	
}

/* scrolls stack_a up to the starting point */

int	where_swap(int *stack_a, int start, int slots)
{
	int	i;

	i = 0;
	while (i < slots)
	{
		if (stack_a[i] == start)
			return (i);
		++i;
	}
	return (-1);
}

/* finds the first nbr of the LIS in stack_a */

void	start_swap(t_struct *s, int	*lis)
{
	int	start;

	start = where_swap(s->stack_a, lis[1], s->slots);
	if (start < 0)
		ft_printf("Wait... WHAT?!?!");
	print_swap(s, start);
	s->stack_a = shift_swap(s->stack_a, lis[1], s->slots);
	free(s->stack_b);
	s->stack_b = lis + 1;
	s->slots_b = lis[0];
	s->stack_a = rem_swap(s->stack_a, lis + 1, s->slots, s->slots_b);
}	

/* scrolls stack_a to the fist nbr of the LIS, then pushes the LIS in stack_b */
