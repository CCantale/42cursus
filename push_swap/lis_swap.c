/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:20:40 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/03 00:06:09 by ccantale         ###   ########.fr       */
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

int	first_swap(int nbr, t_lis *lis)
{
	int	max;
	int	done;

	done = 0;
	max = lis->max_nbr;
	while (max > 0)
	{
		done = add_swap(lis, nbr, max);
		if (done > 0)
			break ;
		--max;
	}
	if (done > 0)
	{
		ft_printf("\n\nfirst_swap()\n\n");
		return (1);
	}
	return (0);
}	

/* checks the longest LISes first. only the last nbrs. If it finds a smaller
** nbr than the current one, it adds it to the back of the LIS and returns 1.
** otherwise it checks LISes smaller by 1 and does the same. If it finds
** nothing, it returns 0 */

int	back_swap(int *curr_lis, int nbr)
{
	int	i;

	i = curr_lis[0] - 1;
	while (i > 0)
	{
		if (curr_lis[i] < nbr)
			return (i);
		--i;
	}
	return (0);
}

/* scrolls this LIS backwards. if finds a nbr smaller
** than the current one, returns its position in the array */

void	take_swap(int *lis, int i, int copy[500], int nbr)
{
	copy[0] = i + 1;
	while (i > 0)
	{
		copy[i] = lis[i];
		--i;
	}
	copy[copy[0]] = nbr;
}

/* copies the suitable LIS in the right slot of sub_lis */

int	choose_swap(t_lis *lis, int sub_lis[500][500], int sub_nbr, int max)
{
	int	i;
	int	j;

	if (max == 1)
		return (0);
	i = 0;
	while (i < sub_nbr)
	{
		if (sub_lis[i][0] == max)
			break ;
		++i;
	}
	j = 1;
	while (j <= max)
	{
		lis->listack[lis->lis_nbr][j] = sub_lis[i][j];
		++j;
	}
	lis->listack[lis->lis_nbr][0] = max;
	++lis->lis_nbr;
	if (max > lis->max_nbr)
		lis->max_nbr = max;
													ft_printf("\n\nthen_swap()\n\nnew_lis = ");
	return (1);
}

/* finds the first subLIS with max numbers in it and copies it
** in the first slot availeable in **listack. If max is 0, does
** nothing and returns 0, otherwise returns 1 */

int	then_swap(int nbr, t_lis *lis)
{
	int	i;
	int	sub_nbr;
	int	sub_lis[500][500];
	int	max;
	int	back;

	max = 0;
	sub_nbr = 0;
																ft_printf("\n\nlis_nbr = %d\n\n", lis->lis_nbr);
	i = 0;
	while (i < lis->lis_nbr)
	{
		back = back_swap(lis->listack[i], nbr);
		if (back != 0 && back > max)
		{
			take_swap(lis->listack[i], back, sub_lis[sub_nbr], nbr);
			++sub_nbr;
			max = back;
		}
		++i;
	}
	return (choose_swap(lis, sub_lis, sub_nbr, max + 1));
}

/* makes a new listack made of subLISes you could add the current
** nbr to, then selects the longest one, adds the nbr to it and
** creates a new official LIS. returns 0 if it finds no suitable 
** LIS for the current nbr */

void	make_swap(int nbr, t_lis *lis)
{
	lis->listack[lis->lis_nbr][0] = 1;
	lis->listack[lis->lis_nbr][1] = nbr;
	if (lis->listack[lis->lis_nbr][0] > lis->max_nbr)
		lis->max_nbr = lis->listack[lis->lis_nbr][0];
	lis->lis_nbr++;
}

/* starts a new LIS that only contains the current nbr */

void	seq_swap(int *stack_a, int slots, t_lis *lis)
{
	int	i;
	int	lap;

	lap = 0;
	i = 0;
	while (i < slots)
	{
		if (first_swap(stack_a[i], lis) == 0 && then_swap(stack_a[i], lis) == 0)
		{
																ft_printf("\n\nmake_swap()\n\n");
			make_swap(stack_a[i], lis);
		}
																int	k;
																int	l;

																k = 0;
																ft_printf("\n\nLAP #%d\n", i);
																while (k < lis->lis_nbr)
																{
																	ft_printf("\n");
																	ft_printf("lis #%d  ", k);
																	l = 0;
																	while (l <= lis->listack[k][0])
																	{
																		ft_printf("%d-", lis->listack[k][l]);
																		++l;
																	}
																	++k;
																}
		++i;
		if (i == slots && lap == 0)
		{
			i = 0;
			lap = 1;
		}
	}
}

/* Type comment here... */

int	*lis_swap(t_struct *s)
{
	t_lis	lis;
	int	i;
	int	j;

	lis.max_nbr = 0;
	lis.lis_nbr = 0;
	seq_swap(s->stack_a, s->slots, &lis);
																ft_printf("\n\nFinale:\n");
																i = 0;
																while (i < lis.lis_nbr)
																{
																	ft_printf("\n");
																	j = 0;
																	ft_printf("lis #%d  ", i);
																	while (j <= lis.listack[i][0])
																	{
																		ft_printf("%d-", lis.listack[i][j]);
																		++j;
																	}
																	++i;
																}
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
																ft_printf("\n\nMAX: \n");
																i = 0;
																while (i <= lis.max[0])
																{
																	ft_printf("%d-", lis.max[i]);
																	++i;
																}
																ft_printf("\n\n");
	return(lis.max);
}

/* applies the LIS sorting algorithm */
