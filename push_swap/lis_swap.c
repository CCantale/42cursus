/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:20:40 by ccantale          #+#    #+#             */
/*   Updated: 2022/05/25 17:05:33 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	add_swap(int *stack, int nbr)
{
	++stack[0];
	stack[stack[0]] = nbr;
}	

/* puts current nbr at the end of this specific LIS, since it's bigger
** than its last nbr */

void	back_swap(int *curr_lis, int nbr, int slots, t_lis *lis)
{
	int	i;
	int	j;

	i = curr_lis[0] - 1;
	while (i > 0)
	{
		if (curr_lis[i] < nbr)
		{
			lis->listack[lis->lis_nbr] = malloc(sizeof(int) * slots + 1);
			lis->listack[lis->lis_nbr][0] = i;
			lis->listack[lis->lis_nbr][i] = nbr;
			j = i - 1;
			while (j > 0)
			{
				lis->listack[lis->lis_nbr][j] = curr_lis[j];
				--j;
			}
			lis->lis_nbr++;
			break ;
		}
		--i;
	}
			
}

/* scrolls this LIS backwards and, if a nbr smaller than the current one is
** found, creates a new LIS from there, adding current nbr at the end */

int	*kill_swap(int *useliss)
{
	free(useliss);
	return (ft_calloc(1, sizeof(int)));
}

/* kills the useless lis */

int	same_swap(int *lis_one, int *lis_two)
{
	int	a;
	int	b;

	a = 1;
	b = 1;
	while (a <= lis_one[0] && b <= lis_two[0])
	{
		if (lis_one[a] == lis_two[b])
			++a;
		if (a > lis_one[0])
			return (1);
		++b;
	}
	return (0);
}

/* returns 1 if all the nbrs in the first LIS are conteined in the second one */

void	dredge_swap(t_lis *lis)
{
	int	i;
	int	j;

	i = 0;
	while (i < lis->lis_nbr)
	{
		if (lis->listack[i][0] > 0)
		{
			j = i + 1;
			while (j != i)
			{
				if (j >= lis->lis_nbr)
					j = 0;
				if (same_swap(lis->listack[i], lis->listack[j]) > 0)
				{
					kill_swap(lis->listack[i]);
					break ;
				}
				++j;
			}
		}
		++i;
	}	
}

/* for each lis, checks if it's completely contained in one of the other
** LISes. if so, replaces it with an array[1] whith just a 0 in it */

void	make_swap(int nbr, int slots, t_lis *lis)
{
	lis->listack[lis->lis_nbr] = malloc(sizeof(int) * slots + 1);
	lis->listack[lis->lis_nbr][0] = 1;	
	lis->listack[lis->lis_nbr][1] = nbr;
	lis->lis_nbr++;	
}

/* starts a new LIS that only contains the current nbr */

void	seq_swap(int *stack_a, int slots, t_lis *lis)
{
	int	i;
	int	j;

	i = 0;
	while (i < slots)
	{
		make_swap(stack_a[i], slots, lis);
		j = i + 1;
		while (j != i)
		{
			if (j == slots)
				j = 0;
			if (stack_a[i] > lis->listack[j][lis->listack[j][0]])
				add_swap(lis->listack[j], stack_a[i]);
			else if (stack_a[i] < lis->listack[j][lis->listack[j][0]])
				back_swap(lis->listack[j], stack_a[i], slots, lis);
			dredge_swap(lis);
			++j;
		}
		++i;
	}
}

/* Ogni nuovo numero viene comparato con l'ultimo numero di ogni LIS.
 * se è più grande, si aggiunge il numero alla LIS, altrimenti controlla
 * il resto della LIS a ritroso. Se si trova un numero più piccolo,
 * si fa un nuovo array che è la copia di quello in questione fino a 
 * quel punto e poi si aggiunge il numero corrente. Alla fine di tutto, si
 * controlla se ci sono array che sono interamente contenuti in altri array
 * e si eliminano gli array in eccesso */

void	lis_swap(t_struct *s)
{
	t_lis	lis;
	//int	lis_rev;

	ft_memset(lis, 0, sizeof(lis));
	seq_swap(s->stack_a, s->slots, &lis, 0);
	/*lis_rev = rev_swap(s->stack_a, s->slots, &seq);
	if (lis_rev > lis)
	{
		lis_rev *= -1;
		start_swap(s, lis_rev);
	}
	else*/
	//		start_swap(s, lis);
	
}

/* applies the LIS sorting algorithm */
