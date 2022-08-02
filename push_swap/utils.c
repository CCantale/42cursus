/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:12:49 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/02 21:54:22 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	small_swap(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

/* returns the smaller nbr */

int	big_swap(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/* returns the bigger nbr */

int	lil_swap(int *array, int slots)
{
	int	i;
	int	min;

	min = 2147483647;
	i = 0;
	while (i < slots)
	{
		if (array[i] < min)
			min = array[i];
		++i;
	}
	i = 0;
	while (i < slots)
	{
		if (array[i] == min)
			return (i);
		++i;
	}
	return (0);
}

/* returns the position of the smallest nbr in the array */

int	fix_swap(int *stack_a, int slots)
{
	int	i;
	int	max;

	max = stack_a[0];
	i = 0;
	while (i < slots)
	{
		if (stack_a[i] > max)
			max = stack_a[i];
		++i;
	}
	i = 0;
	while (i < slots)
	{
		if (stack_a[i] == max)
		{
			if (i + 1 == slots)
				return (0);
			else
				return (i + 1);
		}
		++i;
	}
	return (0);
}

/* returns the position right next to the highest nbr in the stack.
** in case the number we're analysing is bigger or smaller than all
** the others, that will be the right slot to put it into */
