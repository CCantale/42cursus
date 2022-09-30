/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:47:48 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/30 16:49:53 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/quit.h"

void	quit(t_info *info)
{
	int	i;

	sem_close(info->death);
	sem_close(info->messages);	
	sem_close(info->forks);
	free(info->sons);
	i = 0;
	while (i < info->nbr_of_philo)
	{
		kill(info->sons[i], SIGKILL);
		++i;
	}
}
