/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:58:14 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/07 18:03:42 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	push_swap(t_struct *s)
{
	int	i;
	int *new_a;
	int	*new_b;

	new_a = malloc(sizeof(int) * s->slots + 1);
	new_b = malloc(sizeof(int) * s->slots_b - 1);
	++s->slots;
	++s->slots_b;
	new_a[0] = s->stack_b[0];
	i = 0;
	while (i < s->slots)
	{
		new_a[i + 1] = s->stack_a[i];
		++i;
	}
	i = 0;
	while (i < s->slots_b)
	{
		new_b[i] = s->stack_b[i];
		++i;
	}
	free(s->stack_a);
	free(s->stack_b);
	s->stack_a = new_a;
	s->stack_b = new_b;
	ft_printf("pa\n");
}

/* performs the notorious pushing technique known as 'pa' */

int small_swap(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

/* returns the smaller nbr */

int big_swap(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/* returns the bigger nbr */

void	r_swap(int steps_a, int steps_b, int dir)
{
	int	i;

	i = 0;
	while (i < steps_a)
	{
		if (dir == 0)
			ft_printf("ra\n");
		if (dir == 1)
			ft_printf("rra\n");
		++i;
	}
	i = 0;
	while (i < steps_b)
	{
		if (dir == 0)
			ft_printf("rb\n");
		if (dir == 1)
			ft_printf("rrb\n");
		++i;
	}
}

/* prints ra, rra, rb and rrb accordingly to the case.
** 
** dir:
** 0 = ra and rrb
** 1 = rra and rb
*/

void arrr_swap(int steps_a, int steps_b, int dir)
{
	int	i;
	int	up_to;

	i = 0;
	up_to = big_swap(steps_a, steps_b) - small_swap(steps_a, steps_b);
	while (i < up_to)
	{
		if (dir == 0)
			ft_printf("rr\n");
		if (dir == 1)
			ft_printf("rrr\n");
		++i;
	}
	while (i < big_swap(steps_a, steps_b))
	{
		if (dir == 0 && steps_a > steps_b)
			ft_printf("ra\n");
		if (dir == 0 && steps_a < steps_b)
			ft_printf("rb\n");
		if (dir == 1 && steps_a > steps_b)
			ft_printf("rra\n");
		if (dir == 1 && steps_a < steps_b)
			ft_printf("rrb\n");
		++i;
	}
}

/* prints rr, rrr, ra, rra, rb and rrb accordingly to the case.
** it only treats the case in which the two stacks are to be
** scrolled in the same direction 
**
** dir:
** 0 = we're scrolling RIGHT to LEFT
** 1 = we're scrolling LEFT to RIGHT
*/

void	scroll_swap(int *stack, int slots, int steps, char dir)
{
	int	i;
	int	j;
	int	up_to;
	int	*temp;

	i = 0;
	j = 0;
	temp = malloc(sizeof(int) * slots);
	if (dir == 0 && steps > 0)
		i = steps;
	else if (steps > 0)
		i = slots - steps;
	up_to = i;
	temp[j] = stack[i++];
	while (i != up_to)
	{
		if (i == slots)
			i = 0;
		temp[j] = stack[i];
		++i;
		++j;
	}
	free(stack);
	stack = temp;
}

/* scrolls the given stack according to steps and dir 
** 
** 0 = scroll RIGHT to LEFT
** 1 = scroll LEFT to RIGHT
*/

void	dir_swap(t_struct *s, int steps_a, int steps_b, int flag)
{
	if (flag == 0 && steps_a > 0)
	{
		scroll_swap(s->stack_a, s->slots, steps_a, 0);
		scroll_swap(s->stack_b, s->slots_b, steps_b, 0);
		arrr_swap(steps_a, steps_b, 0);
	}
	if (flag == 0 && steps_a < 0)
	{
		scroll_swap(s->stack_a, s->slots, steps_a * -1, 1);
		scroll_swap(s->stack_b, s->slots_b, steps_b * -1, 1);
		arrr_swap(steps_a * -1, steps_b * -1, 0);
	}
	if (flag == 1 && steps_a > 0)
	{
		scroll_swap(s->stack_a, s->slots, steps_a, 0);
		scroll_swap(s->stack_b, s->slots_b, steps_b * -1, 1);
		r_swap(steps_a, steps_b, 0);
	}
	if (flag == 1 && steps_a < 0)
	{
		scroll_swap(s->stack_a, s->slots, steps_a * -1, 1);
		scroll_swap(s->stack_b, s->slots_b, steps_b, 0);
		r_swap(steps_a, steps_b, 1);
	}
	push_swap(s);
}

/* uses scroll_swap() to scoll the stacks and then activates push_swap() */

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

int	min_swap(int *scores, int slots)
{
	int	i;
	int min;

	min = slots;
	i = 0;
	while (i < slots)
	{
		if (scores[i] < min)
			min = scores[i];
		++i;
	}
	i = 0;
	while (i < slots)
	{
		if (scores[i] == min)
			return (i);
		++i;
	}
	return (0);
}

/* returns the position of the smallest score in scores[] */

void	next_swap(t_struct *s, int *scores)
{
	int	sub_scores[4];
	int	next;
	int	same_dir;
	int	opp_dir;

	next = min_swap(scores, s->slots_b) + 1;
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

void	end_swap(t_struct *s)
{
	int	*new_a;
	int	i;

	free(s->stack_a - 1);
	new_a = malloc(sizeof(int) * (s->slots + s->slots_b));
	if (!new_a)
	{
		free(s->stack_b);
		exit(1);
	}
	i = 0;
	while (i < s->slots)
	{
		new_a[i] = s->stack_a[i];
		++i;
	}
	s->stack_a = new_a;
	i = 0;
	while (s->slots_b > 0)
	{
		next_swap(s, prof_swap(s));
	}
																					ft_printf("\n\n\n\nSEASON FINALE!\n\nslots_a = %d\n\n", s->slots);
																					i = 0;
																					while (i < s->slots)
																					{
																						ft_printf("%d ", s->stack_a[i]);
																						++i;
																					}
																					ft_printf("\n\n");
}

/* season finale! reallocates s->stack_a, then pushes nbrs back in stack_a, 
** one by one, using prof_swap() every time to get the best nbr to push */
