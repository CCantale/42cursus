/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:58:14 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/06 00:24:11 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	mid_swap(t_struct *s, int *sub_scores, int info, int dir)
{
	int	rr;
	int	rrr;

	if (dir == 0)
	{
		if (sub_scores[0] > sub_scores[2])
			rr = sub_scores[0];
		else
			rr = sub_scores[2];
		if (sub_scores[1] > sub_scores[3])
			rrr = sub_scores[1];
		else
			rrr = sub_scores[3];
		if (score_r < score_rr)
			push_swap(s, sub_score[0], sub_score[2], 0);
		else
			push_swap(s, sub_score[1] * -1, sub_score[3] * -1, 0);
	}
	else if (dir == 1)
	{
		if (sub_scores[0] + sub_scores[3] < sub_scores[1] + sub_scores[2])
			push_swap(s, sub_scores[0], sub_scores[3] * -1, 1);
		else
			push_swap(s, sub_scores[1] * -1, sub_scores[2], 1);
	}
}

/* uses the sub_scores[4] and the hint about the direction to get
*** all the info required by push_swap() */

void	next_swap(t_structure *s, int *scores)
{
	int	sub_scores[4];
	int	next;
	int	same_dir;
	int	opp_dir;

	next = min_swap(scores) + 1;
	if (next == s->slots_b)
		next = 0;
	sub_swap(s, s->stack_b[next], sub_scores, next);
	same_dir = same_swap(sub_scores);
	opp_dir = opp_swap(sub_scores);
	if (same_dir < opp_dir)
		mid_swap(s, sub_scores, same_dir, 0);
	else
		mid_swap(s, sub_scores, opp_dir, 1);
}

/* makes sub_scores again and gets how to scroll the stacks,
** mid_swap() and then push_swap() will do the rest */

void	end_swap(t_structure *s)
{
	int	i;

	i = 0;
	while (s->slots_b > 0)
	{
		next_swap(s, help_swap(s));
	} 
}

/* season finale! pushes nbrs back in stack_a, one by one, 
** and uses help_swap() every time to get the best nbr to push */
