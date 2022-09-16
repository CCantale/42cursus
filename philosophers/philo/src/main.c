/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:35:39 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/16 12:16:45 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	main(int argc, char **argv)
{
	t_ime	relativity;

	if (argc < 5 || argc > 6)
		return (mistake(" We're only allowed 4 or 5 arguments in life,"
				" that's all.\n Come on, try again."));
	if (inform(&relativity, argv, argc))
		return (1);
	relativity.start = 0;
	relativity.start = phi_time(&relativity);
	dinner(&relativity);
	wait_why_dont_we_use_one_fork_each(&relativity);
	return (0);
}
