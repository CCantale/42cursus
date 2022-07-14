/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prof_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:41:49 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/14 17:23:07 by evento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	opp_swap(int sub_scores[4])
{
	if (sub_scores[0] + sub_scores[3] < sub_scores[1] + sub_scores[2])
		return (sub_scores[0] + sub_scores[3]);
	else
		return(sub_scores[1] + sub_scores[2]);
}

/* considers the two options that move in opposite directions
** (ra and rrb, rra and rb), sums them and returns the smaller one */

int	same_swap(int sub_scores[4])
{
	int	score_r;
	int	score_rr;

	if (sub_scores[0] > sub_scores[2])
		score_r = sub_scores[0];
	else
		score_r = sub_scores[2];
	if (sub_scores[1] > sub_scores[3])
		score_rr = sub_scores[1];
	else
		score_rr = sub_scores[3];
	if (score_r < score_rr)
		return (score_r);
	else
		return (score_rr);
}

/* considers the two options that move in the same direction
** (ra and rb, rra and rrb), chooses the biggest in both pairs
** and then returns the smaller one */ 

void sub_swap(t_struct *s, int nbr, int sub_scores[4], int pos_b)
{
	int	i;
	int next;

	sub_scores[0] = 0;
	next = 1;
	i = 0;
	while (i < s->slots)
	{
		if (s->stack_a[i] < nbr && s->stack_a[next] > nbr)
		{
			sub_scores[0] = next;
			break ;
		}
		++i;
		++next;
		if (next == s->slots)
			next = 0;
	}
	sub_scores[1] = s->slots - sub_scores[0];
	sub_scores[2] = pos_b;
	sub_scores[3] = s->slots_b - sub_scores[2];
}

/* fills in the 4 slots of sub_scores:
** 
** sub_scores[0] è la distanza da percorrere in slot_a usando ra
** sub_scores[1] "                                          " rra
** sub_scores[2] "                            " slot_b usando rb
** sub_scores[3] "                                          " rrb 
*/

void	score_swap(t_struct *s, int *scores, int pos_b)
{
	int	same_score;
	int opp_score;
	int sub_scores[4];

	sub_swap(s, s->stack_b[pos_b], sub_scores, pos_b);
	same_score = same_swap(sub_scores);
	opp_score = opp_swap(sub_scores);
	if (same_score < opp_score)
		scores[pos_b] = same_score;
	else
		scores[pos_b] = opp_score;
}

/*finds the score for the current nbr and puts the score in the scores array */

int	*prof_swap(t_struct *s)
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
																	//if (firstime == 0)
																	//{
																		ft_printf("\n\n\nSCORES = ");
																		i = 0;
																		while (i < s->slots_b)
																		{
																			ft_printf("%d ", scores[i]);
																			++i;
																		}
																		ft_printf("\n\n\n");
																	//}
	return (scores);
}

/* returns an array that contains a score for each and every nbr in s->stack_b.
** the vote is obtained by calculating the number of moves necessary to get
** that nbr to the top of the stack AND to scroll s->stack_a up to the correct
** slot. if the two directions are opposite to one another, the algorithm sums the
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
