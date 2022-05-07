/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:20:40 by ccantale          #+#    #+#             */
/*   Updated: 2022/05/07 20:59:52 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	pmet_swap(int curr_num, int seq->temp, int *j, int *sequence)
{
	if (curr_num > seq->temp)
	{
		seq->temp = curr_num;
		*sequence += 1;
	}
	*j -= 1;
	return (seq->temp);
}

/* it's seq->temp_swap(), but... you got it, right? */

int	rev_swap(int *stack_a, int slots)
{
	int	i;
	int	j;
	int	seq->temp;
	int	sequence;
	int	max_seq[2];

	seq->temp = stack_a[slots - 1];
	max_seq[0] = 0;
	max_seq[1] = 0;
	i = slots - 1;
	while (i >= 0)
	{
		sequence = 0;
		j = slots - 1;
		while (j >= 0)
			seq->temp = pmet_swap(stack_a[j], seq->temp, &j, &sequence);
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

int	seq->temp_swap(int curr_num, int seq->temp, int *j, int *sequence)
{
	if (curr_num > seq->temp)
	{
		seq->temp = curr_num;
		*sequence += 1;
	}
	*j += 1;
	return (seq->temp);
}

/* makes seq->temp (highest number so far) equal to the current
** number, if it's bigger. then increments j */

int	seq_swap(int *stack_a, int slots)
{
	int	i;
	int	j;
	int	seq->temp;
	int	sequence;
	int	max_seq[2];

	seq->temp = stack_a[0];
	max_seq[0] = 0;
	max_seq[1] = 0;
	i = 0;
	while (i < slots)
	{
		sequence = 0;
		j = 0;
		while (j < slots)
			seq->temp = seq->temp_swap(stack_a[j], seq->temp, &j, &sequence);
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
	lis = seq_swap(s->stack_a, s->slots, &seq);
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


void	seq_swap(int *stack_a, int slots, t_lis *seq)
{
	if (seq->pos < slots)
	{
		seq->temp = seq->cur_pos;
		seq->cur_pos++;
		if (seq->cur_pos == slots)
			seq->cur_pos = 0;
		while (stack_a[seq->cur_pos] < stack_a[seq->temp])
		{
			seq->cur_pos++;
			if (seq->cur_pos == slots)
				seq->cur_pos = 0;
		}
		while (seq->cur_pos != seq->temp)
		{
			seq->cur_seq++;
			seq_swap(stack_a, slots, seq);
			seq->cur_pos = 
		}
		if (seq->cur_seq > seq->max_seq)
		{
			seq->max->seq = seq->cur_seq;
			seq->lis = seq->pos;
		}
		seq->pos++;
		seq_swap(stack_a, slots, seq);
	}
}
