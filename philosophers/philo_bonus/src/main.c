/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:52:01 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/04 19:41:04 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	philo;

	if (argc < 5 || argc > 6)
	{
		printf("Five or six arguments only, sir, if you please.\n");
		return (1);
	}
	if (set_struct(&info, &philo, argv, argc))
		return (1);
	start(&info);
	if (philo.pid)
		quit(&info);
	return (0);
}
