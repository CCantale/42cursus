/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_then_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:32:10 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/02 21:37:07 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
		return (1);
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
