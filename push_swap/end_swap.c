/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:58:14 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/02 21:23:55 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	push_swap(t_struct *s)
{
	int	i;
	int	*new_a;
	int	*new_b;

	new_a = malloc(sizeof(int) * s->slots + 1);
	new_b = malloc(sizeof(int) * s->slots_b - 1);
	new_a[0] = s->stack_b[0];
	i = 0;
	while (i < s->slots)
	{
		new_a[i + 1] = s->stack_a[i];
		++i;
	}
	i = -1;
	while (++i < s->slots_b)
		new_b[i] = s->stack_b[i + 1];
	++s->slots;
	--s->slots_b;
	free(s->stack_a);
	free(s->stack_b);
	s->stack_a = new_a;
	s->stack_b = new_b;
	ft_printf("pa\n");
}

/* performs the notorious pushing technique known as 'pa' */

void	dir_swap(t_struct *s, int steps_a, int steps_b, int flag)
{
	if (flag == 0 && steps_a >= 0)
	{
		s->stack_a = scroll_swap(s->stack_a, s->slots, steps_a, 0);
		s->stack_b = scroll_swap(s->stack_b, s->slots_b, steps_b, 0);
		arrr_swap(steps_a, steps_b, 0);
	}
	else if (flag == 0)
	{
		s->stack_a = scroll_swap(s->stack_a, s->slots, steps_a * -1, 1);
		s->stack_b = scroll_swap(s->stack_b, s->slots_b, steps_b * -1, 1);
		arrr_swap(steps_a * -1, steps_b * -1, 1);
	}
	else if (flag == 1 && steps_a >= 0 && steps_b <= 0)
	{
		s->stack_a = scroll_swap(s->stack_a, s->slots, steps_a, 0);
		s->stack_b = scroll_swap(s->stack_b, s->slots_b, steps_b * -1, 1);
		r_swap(steps_a, steps_b * -1, 0);
	}
	else if (flag == 1)
	{
		s->stack_a = scroll_swap(s->stack_a, s->slots, steps_a * -1, 1);
		s->stack_b = scroll_swap(s->stack_b, s->slots_b, steps_b, 0);
		r_swap(steps_a * -1, steps_b, 1);
	}
	push_swap(s);
}

/* uses scroll_swap() to scoll the stacks and then activates push_swap(),
** then ar_swap() and arrr_swap() print the moves. They're both in arrr.c */

void	mid_swap(t_struct *s, int *sub_scores, int dir)
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
		if (rr < rrr)
			dir_swap(s, sub_scores[0], sub_scores[2], 0);
		else
			dir_swap(s, sub_scores[1] * -1, sub_scores[3] * -1, 0);
	}
	else if (dir == 1)
	{
		if (sub_scores[0] + sub_scores[3] < sub_scores[1] + sub_scores[2])
			dir_swap(s, sub_scores[0], sub_scores[3] * -1, 1);
		else
			dir_swap(s, sub_scores[1] * -1, sub_scores[2], 1);
	}
}

/* uses the sub_scores[4] and the hint about the direction to get
** all the info required by dir_swap() */

void	next_swap(t_struct *s, int *scores)
{
	int	sub_scores[4];
	int	next;
	int	same_dir;
	int	opp_dir;

	next = lil_swap(scores, s->slots_b);
	sub_swap(s, s->stack_b[next], sub_scores, next);
	same_dir = same_swap(sub_scores);
	opp_dir = opp_swap(sub_scores);
	free(scores);
	if (same_dir < opp_dir)
		mid_swap(s, sub_scores, 0);
	else
		mid_swap(s, sub_scores, 1);
}

/* makes sub_scores again and gets how to scroll the stacks,
** mid_swap(), dir_swap() and push_swap() will do the rest */

void	end_swap(t_struct *s)
{
	int	i;
	int	last_scroll;

	i = 0;
	while (s->slots_b > 0)
	{
		next_swap(s, prof_swap(s));
	}
	last_scroll = lil_swap(s->stack_a, s->slots);
	print_swap(s, last_scroll);
	if (last_scroll <= s->slots / 2)
		s->stack_a = scroll_swap(s->stack_a, s->slots, last_scroll, 0);
	else
		s->stack_a = scroll_swap(s->stack_a,
				s->slots, s->slots - last_scroll, 1);
}

/* season finale! reallocates s->stack_a, then pushes nbrs back in stack_a, 
** one by one, using prof_swap() every time to get the best nbr to push.
** then, the stack is properly scrolled to find its final form */
