/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:25:54 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/02 21:57:05 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	rev_swap(int *array, int slots)
{
	int	beg;
	int	end;
	int	temp;

	beg = 0;
	end = slots - 1;
	while (beg < end)
	{
		temp = array[beg];
		array[beg] = array[end];
		array[end] = temp;
		++beg;
		--end;
	}
}

/* reverses an array */
