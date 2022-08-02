/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:21:46 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/02 21:23:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	*scroll_swap(int *stack, int slots, int steps, int dir)
{
	int	i;
	int	j;
	int	up_to;
	int	*temp;

	if (steps == 0)
		return (stack);
	i = 0;
	j = 0;
	temp = malloc(sizeof(int) * slots);
	if (dir == 0)
		i = steps;
	else if (dir == 1)
		i = slots - steps;
	up_to = i;
	temp[j++] = stack[i++];
	while (i != up_to)
	{
		if (i == slots)
			i = 0;
		temp[j++] = stack[i++];
	}
	free(stack);
	return (temp);
}

/* scrolls the given stack according to steps and dir 
** 
** 0 = scroll RIGHT to LEFT
** 1 = scroll LEFT to RIGHT
*/
