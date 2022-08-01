/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:30:00 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/01 14:30:33 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int argc, char **argv)
{
	t_struct	s;

	if (argc == 1)
		return (0);
	s.slots = 0;
	s.slots_b = 0;
	s.stack_a = get_swap(argc, argv, &s.slots);
	if (!s.stack_a)
		return (0);
	if (right_swap(s.stack_a, s.slots) == 0)
	{
														int	i;
														i = 0;
														ft_printf("\n\n");
														while (i < s.slots)
														{
															ft_printf("%d ", s.stack_a[i]);
															++i;
														}
														ft_printf("\n\n");
		end_swap(&s);
		free(s.stack_a);
		return(0);
	}
	if (s.slots == 2)
		two_swap(&s);
	else if (s.slots == 3)
		three_swap(&s);
	else if (s.slots == 4 || s.slots == 5)
		five_swap(&s);
	else if (s.slots > 5)
	{
		start_swap(&s, lis_swap(&s));
		end_swap(&s);
	}
	free(s.stack_a);
	free(s.stack_b);
	return (0);
}
