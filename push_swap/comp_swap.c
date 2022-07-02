/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:25:29 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/03 00:50:20 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	comp_swap()
{

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
