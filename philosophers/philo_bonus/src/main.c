/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:52:01 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/30 17:56:52 by ccantale         ###   ########.fr       */
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
	if (set_sons(&info))
		return (1);
	if (set_struct(&info, &philo, argv, argc))
		return (1);
	start(&info);
	if (philo.pid)
		quit(&info);
	printf("\n\n                \033[0;36mEND OF CODE\033[0m\n\n");
	return (0);
}

int	set_sons(t_info *info)
{
	info->sons = malloc(sizeof(pid_t) * info->nbr_of_philo);
	if (!info->sons)
		return (1);
	return (0);
}
