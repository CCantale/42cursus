/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:30:00 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/02 21:45:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	call_swap(t_struct *s, int slots)
{
	if (slots == 2)
		two_swap(s);
	else if (slots == 3)
		three_swap(s);
	else if (slots == 4 || slots == 5)
		five_swap(s);
	else if (slots > 5)
	{
		start_swap(s, lis_swap(s));
		end_swap(s);
	}
}

/* chooses the right function to call, depending on
** the number of slots in stack_a */

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
		end_swap(&s);
		free(s.stack_a);
		return (0);
	}
	call_swap(&s, s.slots);
	free(s.stack_a);
	free(s.stack_b);
	return (0);
}
