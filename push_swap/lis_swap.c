/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:20:40 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/02 21:35:28 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	add_swap(t_lis *lis, int nbr, int max)
{
	int	i;
	int	done;

	done = 0;
	i = 0;
	while (i < lis->lis_nbr && done == 0)
	{
		if (lis->listack[i][0] == max
				&& nbr > lis->listack[i][lis->listack[i][0]])
		{
			++lis->listack[i][0];
			lis->listack[i][lis->listack[i][0]] = nbr;
			done = 1;
			if (lis->listack[i][0] > lis->max_nbr)
				lis->max_nbr = lis->listack[i][0];
		}
		++i;
	}
	return (done);
}	

/* checks and adds */

void	make_swap(int nbr, t_lis *lis)
{
	lis->listack[lis->lis_nbr][0] = 1;
	lis->listack[lis->lis_nbr][1] = nbr;
	if (lis->listack[lis->lis_nbr][0] > lis->max_nbr)
		lis->max_nbr = lis->listack[lis->lis_nbr][0];
	lis->lis_nbr++;
}

/* starts a new LIS that only contains the current nbr */

void	seq_swap(int *stack_a, int slots, t_lis *lis, int end)
{
	int	i;

	i = end + 1;
	if (i == slots)
		i = 0;
	while (i != end)
	{
		if (first_swap(stack_a[i], lis) == 0 && then_swap(stack_a[i], lis) == 0)
		{
			make_swap(stack_a[i], lis);
		}
		++i;
		if (i == slots)
			i = 0;
	}
}

/* Type comment here... */

int	min_swap(int *stack_a, int slots)
{
	int	i;
	int	min;

	min = stack_a[0];
	i = 0;
	while (i < slots)
	{
		if (stack_a[i] < min)
			min = stack_a[i];
		++i;
	}
	i = 0;
	while (i < slots)
	{
		if (stack_a[i] == min)
		{
			if (i != 0)
				return (i - 1);
			else
				return (slots - 1);
		}
		++i;
	}
	return (0);
}

/* finds position of the nbr that comes
** right before the smallest one in stack_a */

int	*lis_swap(t_struct *s)
{
	t_lis	lis;
	int		i;
	int		j;

	lis.max_nbr = 0;
	lis.lis_nbr = 0;
	seq_swap(s->stack_a, s->slots, &lis, min_swap(s->stack_a, s->slots));
	i = 0;
	while (i < lis.lis_nbr)
	{
		if (lis.listack[i][0] == lis.max_nbr)
		{
			lis.max = malloc(sizeof(int) * lis.max_nbr + 1);
			j = 0;
			while (j <= lis.max_nbr)
			{
				lis.max[j] = lis.listack[i][j];
				++j;
			}
			break ;
		}
		++i;
	}
	return (lis.max);
}

/* applies the LIS sorting algorithm */
