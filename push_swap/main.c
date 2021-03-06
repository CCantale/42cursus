/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:30:00 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/21 15:04:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int argc, char **argv)
{
	t_struct	s;

	if (argc == 1)
		return (0);
	s.slots = 0;
	s.stack_a = get_swap(argc, argv, &s.slots);
	if (!s.stack_a)
		return (0);
	start_swap(&s, lis_swap(&s));
	end_swap(&s);
	free(s.stack_a);
	free(s.stack_b);
	return (0);
}
