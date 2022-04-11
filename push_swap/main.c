/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:30:00 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/11 17:00:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int argc, char **argv)
{
	int	*stack_a;

	if (argc == 1)
		return (0);
	stack_a = get_swap(argc, argv);
	if (!stack_a)
		return (0);
	return (0);
}
