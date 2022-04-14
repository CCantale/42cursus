/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:30:00 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/14 19:11:23 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	slots;

	if (argc == 1)
		return (0);
	slots = 0;
	stack_a = get_swap(argc, argv, &slots);
	if (!stack_a)
		return (0);
	lis_swap(stack_a, stack_b, slots);
	free(stack_a);
	free(stack_b);
	return (0);
}
