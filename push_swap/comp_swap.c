/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:25:29 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/04 15:50:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	alt_swap(t_struct *s, int score_a, int score_b, int flag)
{
	int	alt_a;
	int	alt_b;

	if (flag > 0)
		score_b *= -1;
	else
		score_a *= -1;
	alt_a = s->slots - score_a;
	if (alt_a > score_a)
		alt_a = alt_a - score_a;
	else
		alt_a = score_a - alt_a;
	alt_b = s->slots_b - score_b;
	if (alt_b > score_b)
		alt_b = alt_b - score_b;
	else
		alt_b = score_b - alt_b;
	if (flag == 0 && alt_a < alt_b)
		return (1);
	else if (flag == 0 && alt_b < alt_a)
		return (-1);
	else if (alt_a < alt_b)
		return (s->slots - score_a);
	else
		return (-1 * (s->slots_b - score_b));
}

/* compare the differences between both paths, ra and rra, rb and rrb and
** returns the smallest one. if the smaller is score_a, the returned nbr is
** positive, otherwise it's negative */

int	b_swap(int slots_b, int pos_r, int sub_scores[4])
{
	sub_scores[2] = pos_r;
	sub_scores[3] = slots_b - sub_scores[2];
	if (sub_scores[0] < sub_scores[1])
		return (sub_scores[0]);
	else
		return (sub_scores[1] * -1);
}

/* returns the smallest nbr of moves to get the nbr in the right position
** in stack_b. if the moves are intended in reverse, the nbr is returned
** as a negative */

int	ska_swap(t_struct *s, int nbr, int sub_scores[4])
{
	int	i;

	i = 0;
	while (i < s->slots)
	{
		if (s->stack_a[i] > nbr)
		{
			sub_scores[0] = i;
			break ;
		}
		++i;
	}
	sub_scores[1] = s->slots - sub_scores[0];
	if (sub_scores[0] < sub_scores[1])
		return (sub_scores[0]);
	else
		return (sub_scores[1] * -1);
}

/* returns the smallest nbr of moves to get stack_a in the right position
** to recieve the current nbr. if the moves are intended in reverse, the 
** nbr is returned as a negative */

void	score_swap(t_struct *s, int *scores, int pos_b)
{
	int	score_a;
	int	score_b;
	int	sub_scores[4];

	alt_score = 0;
	score_a = ska_swap(s, s->tack_b[pos_b], sub_scores);
	score_b = b_swap(s->slots_b, pos_b, sub_scores);
	if (score_a > 0 && score_b > 0)
		scores[pos_b] = score_a + score_b;
	else if (score_a < 0 && score_b < 0)
		scores[pos_b] = -1 * (score_a - score_b);
	................
}

/*finds the score for the current nbr and puts the score in the scores array */

int	*comp_swap(t_struct *s)
{
	int	i;
	int	*scores;

	scores = malloc(sizeof(int) * s->slots_b);
	i = 0;
	while (i < s->slots_b)
	{
		score_swap(s, scores, i);
		++i;
	}
	return (scores);
}

/* makes an array that contains a score for each and every nbr in s->stack_b.
** the vote is obtained by calculating the number of moves necessary to get
** that nbr to the top of the stack AND to scroll s->stack_a up to the correct
** slot. if the two directions are opposite to one another, the syetem sums the
** two nbrs, otherwise it only takes the bigger one and counts that as the total
** score. finally, returns the winner nbr, i.e. the one with the lowest score.

	es. stack_a 00000058000

	    stack_b 006000

	to bring 5 to the top it needs +5 or -6 moves
	to get 6 it needs +4 or -2

	+5 and -2 are the lowest. They get a score of 7

	try and change one of the two directions. 
	5 to 6 is the best.

	we thus have -6 and -2 
	They get a score of 6

	6 is smaller than 7, therfore this one strategy is the winner

	rrr
	rrr
	rrr
	rrr
	rra
	rra
	pa
*/
