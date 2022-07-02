/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:20:40 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/02 13:15:34 by ccantale         ###   ########.fr       */
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
		}
		++i;
	}
	if (lis->listack[i][0] > lis->max_nbr)
		lis->max_nbr = lis->listack[i][0];
	return (done);
}	

/* checks and adds */

int	first_swap(t_lis *lis, int nbr)
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

/* checks the longest LISes first. only the last nbrs. If it finds a smalller
** nbr than the current one, it adds it to the back of the LIS and returns 1.
** otherwise it checks LISes smaller by 1 and does the same. If it finds
** nothing, it returns 0 */

int	seek_swap(t_lis *lis)
{
	int	i;

	i = 0;
	while (i < lis->lis_nbr)
	{
		if (lis->listack[i][0] == 0)
		{
			free(lis->listack[i]);
			return (i);
		}
		++i;
	}
	lis->lis_nbr += 1;
	return (lis->lis_nbr - 1);
}

/* seeks for an empty slot to put the new LIS. if there's none returns lis_nbr */

int	back_swap(int *curr_lis, int nbr)
{
	int	i;

	if (curr_lis[0] == 0)
		return (0);
	i = curr_lis[0] - 1;
	while (i > 0)
	{
		if (curr_lis[i] < nbr)
			return (i);
		--i;
	}
	return (0);
}

/* scrolls this LIS backwards and returns 1 if finds
** a nbr smaller than the current one  */

void	take_swap(int *lis, int lislots, int *copy, int nbr)
{
	int	i;

	i = 0;
	while (i < lislots)
	{
		copy[i] = lis[i];
		++i;
	}
	copy[i] = nbr;
	++copy[0];
}

/* copies the suitable LIS in the right slot of sub_lis */

int	choose_swap(t_lis *lis, int sub_lis[500][500], int sub_nbr, int max)
{
	int	i;
	int	j;

	if (max == 0)
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
	//sub_lis = malloc(sizeof(int *) * lis->lis_nbr);
	i = 0;
	while (i < lis->lis_nbr)
	{
		back = back_swap(lis->listack[i], nbr);
		if (back != 0 && back > max)
		{
			//sub_lis[sub_nbr] = malloc(sizeof(int) * slots);
			take_swap(lis->listack[i],
					lis->listack[i][0] + 1, sub_lis[sub_nbr], nbr);
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

int	*kill_swap(int *useliss)
{
	free(useliss);
	useliss = malloc(sizeof(int));
	useliss[0] = 0;
	return (useliss);
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

/* returns 1 if all the nbrs in the first LIS are contained in the second one */

//void	dredge_swap(t_lis *lis, int *curr_lis, int pos, int lis_nbr_now)
//void	dredge_swap(t_lis *lis)
//{
	/*int	i;

	i = 0;
	while (i < lis_nbr_now)
	{
		if (lis->listack[i][0] != 0 && i != pos
				&& same_swap(curr_lis, lis->listack[i]) > 0)
		{
			curr_lis = kill_swap(curr_lis);
			break ;
		}
		++i;
	}*/

/*	int	i;
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
					break ;
				}
				++j;
			}
		}
		++i;
	}
}*/

/* for each LIS, checks if it's completely contained in one of the other
** LISes. if so, replaces it with an array[1] whith just a 0 in it */

void	make_swap(int nbr, t_lis *lis)
{
	lis->listack[lis->lis_nbr][0] = 1;
	lis->listack[lis->lis_nbr][1] = nbr;
	if (lis->listack[lis->lis_nbr][0] > lis->max_nbr)
		lis->max_nbr = lis->listack[lis->lis_nbr][0];
	lis->lis_nbr++;
}

/* starts a new LIS that only contains the current nbr */

/*int	place_swap(t_lis *lis, int curr_nbr, int j, int slots)
{
	int	back;

	back = 0;
	if (curr_nbr > lis->listack[j][lis->listack[j][0]])
	{
		add_swap(lis->listack[j], curr_nbr);
		back = 1;
	}
	else if (curr_nbr < lis->listack[j][lis->listack[j][0]])
	{
		back += back_swap(lis->listack[j], curr_nbr, slots, lis);
	}
	return (back);
}*/

void	seq_swap(int *stack_a, int slots, t_lis *lis)
{
	int	i;
	/*int	j;
	int	back;

	back = 0;*/
	i = 0;
	while (i < slots)
	{
		if (first_swap(lis, stack_a[i]) == 0 && then_swap(stack_a[i], lis) == 0)
			make_swap(stack_a[i], lis);
		/*j = 0;
		while (j < lis->lis_nbr)
		{
			if (lis->listack[j][0] != 0 && lis->listack[j][0] + slots - i > lis->max_nbr)
				back = place_swap(lis, stack_a[i], j, slots);
			if (lis->listack[j][0] > lis->max_nbr)
				lis->max_nbr = lis->listack[j][0];
			++j;
		}
		dredge_swap(lis);
		if (back == 0)
			make_swap(stack_a[i], slots, lis);
		back = 0;*/
		++i;
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
	}
}

/* Ogni nuovo numero viene comparato con l'ultimo numero di ogni LIS.
 * se è più grande, si aggiunge il numero alla LIS, altrimenti controlla
 * il resto della LIS a ritroso. Se si trova un numero più piccolo,
 * si fa un nuovo array che è la copia di quello in questione fino a 
 * quel punto e poi si aggiunge il numero corrente. Alla fine di tutto, si
 * controlla se ci sono array che sono interamente contenuti in altri array
 * e si eliminano gli array in eccesso */

void	free_swap(t_lis *lis)
{
	int	i;
	int	found;

								ft_printf("\n\nmax = %d e nbr = %d\n\n", lis->max_nbr, lis->lis_nbr);
	found = 0;
	i = 0;
	while (i < lis->lis_nbr)
	{
		if (lis->listack[i][0] > lis->max_nbr)
			lis->max_nbr = lis->listack[i][0];
		if (found == 0 && lis->listack[i][0] == lis->max_nbr)
		{
			lis->max = lis->listack[i];
								ft_printf("\n\nmax = %d e lis->listack[i][0] = %d\n\n", lis->max_nbr, lis->listack[i][0]);
			found = 1;
		}
		else
			free(lis->listack[i]);
		++i;
	}
	free(lis->listack);
}

/* saves the longest LIS in lis->max and free()s the rest */

void	struct_swap(t_lis *lis)
{
	lis->max_nbr = 0;
	lis->lis_nbr = 0;
	//lis->listack = malloc(sizeof(int *) * slots * 1000);
	//lis->listack[0] = ft_calloc(1, sizeof(int));
}

/* initializes the lis struct */ 

int	*lis_swap(t_struct *s)
{
	t_lis	lis;
																int	i;
																int	j;

	struct_swap(&lis);
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
	//free_swap(&lis);
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
	}
																ft_printf("\n\nMAX: \n");
																i = 0;
																while (i <= lis.max[0])
																{
																	ft_printf("%d-", lis.max[i]);
																	++i;
																}
	return(lis.max);
}

/* applies the LIS sorting algorithm */
