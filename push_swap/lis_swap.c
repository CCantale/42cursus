/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:20:40 by ccantale          #+#    #+#             */
/*   Updated: 2022/05/06 17:00:37 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	pmet_swap(int curr_num, int temp, int *j, int *sequence)
{
	if (curr_num > temp)
	{
		temp = curr_num;
		*sequence += 1;
	}
	*j -= 1;
	return (temp);
}

/* it's temp_swap(), but... you got it, right? */

int	rev_swap(int *stack_a, int slots)
{
	int	i;
	int	j;
	int	temp;
	int	sequence;
	int	max_seq[2];

	temp = stack_a[slots - 1];
	max_seq[0] = 0;
	max_seq[1] = 0;
	i = slots - 1;
	while (i >= 0)
	{
		sequence = 0;
		j = slots - 1;
		while (j >= 0)
			temp = pmet_swap(stack_a[j], temp, &j, &sequence);
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

int	temp_swap(int curr_num, int temp, int *j, int *sequence)
{
	if (curr_num > temp)
	{
		temp = curr_num;
		*sequence += 1;
	}
	*j += 1;
	return (temp);
}

/* makes temp (highest number so far) equal to the current
** number, if it's bigger. then increments j */

int	seq_swap(int *stack_a, int slots)
{
	int	i;
	int	j;
	int	temp;
	int	sequence;
	int	max_seq[2];

	temp = stack_a[0];
	max_seq[0] = 0;
	max_seq[1] = 0;
	i = 0;
	while (i < slots)
	{
		sequence = 0;
		j = 0;
		while (j < slots)
			temp = temp_swap(stack_a[j], temp, &j, &sequence);
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
** and returns position of the first element */

void	lis_swap(t_struct *s)
{
	int	seq;
	int	seq_rev;

	seq = seq_swap(s->stack_a, s->slots);
	seq_rev = rev_swap(s->stack_a, s->slots);
	if (seq_rev > seq)
	{
		seq_rev *= -1;
		start_swap(s, seq_rev);
	}
	else
		start_swap(s, seq);
}

/* applies the LIS sorting algorithm */
