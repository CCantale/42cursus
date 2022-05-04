/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:17:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/14 19:13:06 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void dnif_swap(int *stack_a, int *stack_b, int start, int slots)
{
}

void find_swap(int *stack_a, int *stack_b, int start, int slots)
{
}

void	start_swap(int *stack_a, int *stack_b, int start, int slots)
{
	if (start > 0)
		find_swap(stack_a, stack_b, start, slots);
	else
	{
		start *= -1;
		dnif_swap(stack_a, stack_b, start, slots);
	}
}	

/* I need the i value from the seq_swap()! */
