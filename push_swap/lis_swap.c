/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:20:40 by ccantale          #+#    #+#             */
/*   Updated: 2022/05/12 19:21:52 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	pmet_swap(int curr_num, int prev, int *j, int *sequence)
{
	if (curr_num > prev)
	{
		prev = curr_num;
		*sequence += 1;
	}
	*j -= 1;
	return (prev);
}

/* it's prev_swap(), but... you got it, right? */

int	rev_swap(int *stack_a, int slots)
{
	int	i;
	int	j;
	int	prev;
	int	sequence;
	int	max_seq[2];

	prev = stack_a[slots - 1];
	max_seq[0] = 0;
	max_seq[1] = 0;
	i = slots - 1;
	while (i >= 0)
	{
		sequence = 0;
		j = slots - 1;
		while (j >= 0)
			prev = pmet_swap(stack_a[j], prev, &j, &sequence);
		if (sequence > max_seq[0])
		{
			max_seq[0] = sequence;
			max_seq[1] = i;
		}
		--i;
	}
	return (max_seq[1]);
}

/* it finds reverse longest sequence */

int	prev_swap(int curr_num, int prev, int *j, int *sequence)
{
	if (curr_num > prev)
	{
		prev = curr_num;
		*sequence += 1;
	}
	*j += 1;
	return (prev);
}

/* makes prev (highest number so far) equal to the current
** number, if it's bigger. then increments j */

int	seq_swap(int *stack_a, int slots)
{
	int	i;
	int	j;
	int	prev;
	int	sequence;
	int	max_seq[2];

	prev = stack_a[0];
	max_seq[0] = 0;
	max_seq[1] = 0;
	i = 0;
	while (i < slots)
	{
		sequence = 0;
		j = 0;
		while (j < slots)
			prev = prev_swap(stack_a[j], prev, &j, &sequence);
		if (sequence > max_seq[0])
		{
			max_seq[0] = sequence;
			max_seq[1] = i;
		}
		++i;
	}
	return (max_seq[1]);
}

/* finds longest sequence of crescent numbers
** and returns seq->position of the first element */

void	lis_swap(t_struct *s)
{
	t_lis	seq;
	int	lis;
	int	lis_rev;

	ft_memset(s, 0, sizeof(*s));
	seq->max = s->stack_a[0];
	seq->burned = ft_calloc(slots, sizeof(int));
	lis = seq_swap(s->stack_a, s->slots, &seq, 0);
	lis_rev = rev_swap(s->stack_a, s->slots, &seq);
	free(seq->burned);
	if (lis_rev > lis)
	{
		lis_rev *= -1;
		start_swap(s, lis_rev);
	}
	else
		start_swap(s, lis);
}

/* applies the LIS sorting algorithm */


/* void	seq_swap(int *stack_a, int slots, t_lis *seq, int prev)
{

	if (now == slots)
		now = 0;
	if  (stack_a[now] < stack_a[prev])
	{
		now++;
		if (now == slots)
			now = 0;
		seq_swap(stack_a, slots, seq, now);
	}
	else if (stack_a[now] > stack_a[prev])
	{
		seq->cur_seq++;
		seq_swap(stack_a, slots, seq, now);
	}
	if (seq->cur_seq > seq->max_seq)
	{
		seq->max_seq = seq->cur_seq;
		seq->lis = seq->pos;
	}
	while (prev == 0 && seq->pos < slots)
	{	
		seq->pos++;
		seq_swap(stack_a, slots, seq, seq->pos);
	}
} */

void	add_swap(int *stack, int nbr)
{
	++stack[0];
	stack[stack[0]] = nbr;
}	

/* puts current nbr at the end of this specific LIS, since it's bigger
** than its last nbr */

void	back_swap(int *stack, int nbr, t_lis lis)
{
	int	i;
	int	j;

	i = stack[0];
	while (i > 0)
	{
		if (stack[i] < nbr)
		{
			lis->listack[lis->lis_nbr] = malloc(sizeof(int) * (i + 2));
			lis->listack[lis->lis_nbr][0] = i;
			lis->listack[lis->lis_nbr][i + 1] = nbr;
			j = i;
			while (j > 0)
			{
				lis->listack[lis->lis_nbr][j] = stack[j];
				--j;
			}
			lis->lis_nbr++;
			break ;
		}
		++i;
	}
			
}

/* scrolls this LIS backwards and, if a nbr smaller than the current one is
** found, creates a new LIS from there, adding current nbr at the end */

void	seq_swap(int stack_a, int slots, t_lis lis)
{
	int	i;
	int	j;

	i = 0;
	while (i < slots)
	{
		j = i + 1;
		while (j != i)
		{
			if (j == slots)
			{
				j = 0;
				continue ;
			}
			if (stack_a[i] > lis->listack[j][listack[j][0]])
				add_swap(lis->listack[j], stack_a[i]);
			else if (stack_a[i] < lis->listack[j][listack[j][0]])
				back_swap(lis->listack[j], stack_a[i], lis);
			dredge_swap();
			++j;
		}
		++i;
	}
}

/* Ogni nuovo numero viene comparato con l'ultimo numero di ogni array.
 * se è più grande, si aggiunge il numero all'array, altrimenti si controlla
 * il numero precedente e così via. Se si trova un numero più piccolo,
 * si fa un nuovo array che è la copia di quello in questione fino a 
 * quel punto e poi si aggiunge il numero corrente. Alla fine di tutto, si
 * controlla se ci sono array che sono interamente contenuti in altri array
 * e si eliminano gli array in eccesso */
