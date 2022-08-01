/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:51:34 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/01 14:51:08 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	right_swap(int *stack_a, int slots)
{
	int i;
	int	j;
	int	stop;

	j = lil_swap(stack_a, slots);
	i = j + 1;
	if (i == slots)
		i = 0;
	stop = j;
	while (i != stop)
	{
		if (stack_a[i] < stack_a[j])
			return (1);
		j = i;
		++i;
		if (i == slots)
			i = 0;
	}
	return (0);
}
