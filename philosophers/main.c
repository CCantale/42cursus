/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:35:39 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/14 20:26:36 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/main.h"

int	main(int argc, char **argv)
{
	t_ime	relativity;

	if (argc < 5 || argc > 6)
		return (mistake(" We're only allowed 5 or 6 arguments in life,"
					" that's all.\n Come on, try again.\"\n"));
	if (argc == 6)
		relativity.how_much_is_enough = phi_atoi(argv[5]);
	else
		relativity.how_much_is_enough = -1;
	if (inform(&relativity, argv))
		return (1);
	return (0);
}

