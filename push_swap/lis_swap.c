/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:20:40 by ccantale          #+#    #+#             */
/*   Updated: 2022/05/27 17:50:45 by ccantale         ###   ########.fr       */
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

int	seek_swap(t_lis *lis)
{
	int	i;

	i = 0;
	while (i < lis->lis_nbr)
	{
		if (lis->listack[i][0] == 0)
			return (i);
		++i;
	}
	return (lis->lis_nbr);
}

/* seeks for an empty slot to put the new LIS. if there's none returns lis_nbr */

void	back_swap(int *curr_lis, int nbr, int slots, t_lis *lis)
{
	int	i;
	int	j;
	int	pos;

	i = curr_lis[0] - 1;
	while (i > 0)
	{
		if (curr_lis[i] < nbr)
		{
			pos = seek_swap(lis);
			lis->listack[pos] = malloc(sizeof(int) * slots + 1);
			lis->listack[pos][0] = i;
			lis->listack[pos][i + 1] = nbr;
			j = i;
			while (j > 0)
			{
				lis->listack[pos][j] = curr_lis[j];
				--j;
			}
			if (pos == lis->lis_nbr)
				lis->lis_nbr += 1;
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
			j = 0;
			while (j < lis->lis_nbr)
			{
				if (lis->listack[j][0] > 0 && j != i
						&& same_swap(lis->listack[i], lis->listack[j]) > 0)
				{
					lis->listack[i] = kill_swap(lis->listack[i]);
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
	int	pos;

	pos = seek_swap(lis);
	lis->listack[pos] = malloc(sizeof(int) * slots + 1);
	lis->listack[pos][0] = 1;	
	lis->listack[pos][1] = nbr;
	if (pos == lis->lis_nbr)
		lis->lis_nbr += 1;	
}

/* starts a new LIS that only contains the current nbr */

void	seq_swap(int *stack_a, int slots, t_lis *lis)
{
	int	i;
	int	j;
																int	k;
																int	l;

	i = 0;
	while (i < slots)
	{
		make_swap(stack_a[i], slots, lis);
		j = 0;
		while (j < lis->lis_nbr)
		{
			if (lis->listack[j][lis->listack[j][0]] > 0 && stack_a[i] > lis->listack[j][lis->listack[j][0]])
				add_swap(lis->listack[j], stack_a[i]);
			else if (lis->listack[j][lis->listack[j][0]] > 0 && stack_a[i] < lis->listack[j][lis->listack[j][0]])
				back_swap(lis->listack[j], stack_a[i], slots, lis);
			++j;
		}
		dredge_swap(lis);
		++i;
																k = 0;
																ft_printf("\n\nlap #%d\n", i);
																while (k < lis->lis_nbr)
																{
																	ft_printf("\n");
																	l = 0;
																	ft_printf("lis #%d  ", k);
																	while (l <= lis->listack[k][0])
																	{
																		ft_printf("%d-", lis->listack[k][l]);
																		++l;
																	}
																	++k;
																}

	}
}

/* Ogni nuovo numero viene comparato con l'ultimo numero di ogni LIS.
 * se è più grande, si aggiunge il numero alla LIS, altrimenti controlla
 * il resto della LIS a ritroso. Se si trova un numero più piccolo,
 * si fa un nuovo array che è la copia di quello in questione fino a 
 * quel punto e poi si aggiunge il numero corrente. Alla fine di tutto, si
 * controlla se ci sono array che sono interamente contenuti in altri array
 * e si eliminano gli array in eccesso */

void	free_swap(int slots, t_lis *lis)
{
	int	i;

	i = 0;
	while (i < lis->lis_nbr)
	{
		if (lis->listack[i][0] > lis->max[0])
		{
			if (lis->max[0] == 0)
				free(lis->max);
			lis->max = lis->listack[i];
		}
		++i;
	}
	i = 0;
	while (i < slots * 2)
	{
		if (lis->listack[i] != lis->max)
			free(lis->listack[i]);
		++i;
	}
	free(lis->listack);
}

/* saves the longest LIS in lis->max and free()s the rest */

void	struct_swap(int slots, t_lis *lis)
{
	lis->max = ft_calloc(1, sizeof(int));
	lis->lis_nbr = 0;
	lis->listack = malloc(sizeof(int *) * (slots * 2));
}

/* initializes the lis struct */ 

int	*lis_swap(t_struct *s)
{
	t_lis	*lis;
																int	i;
																int	j;

	lis = malloc(sizeof(t_lis));
	struct_swap(s->slots, lis);
	seq_swap(s->stack_a, s->slots, lis);
																ft_printf("\n\nFinale:\n");
																i = 0;
																while (i < lis->lis_nbr)
																{
																	ft_printf("\n");
																	j = 0;
																	ft_printf("lis #%d  ", i);
																	while (j <= lis->listack[i][0])
																	{
																		ft_printf("%d-", lis->listack[i][j]);
																		++j;
																	}
																	++i;
																}
	free_swap(s->slots, lis);
																ft_printf("\n\nMAX: \n");
																i = 0;
																while (i <= lis->max[0])
																{
																	ft_printf("%d-", lis->max[i]);
																	++i;
																}
	free(lis);
	return(lis->max);
}

/* applies the LIS sorting algorithm */
