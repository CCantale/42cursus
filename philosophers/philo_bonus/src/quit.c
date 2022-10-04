/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:47:48 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/04 16:36:12 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/quit.h"

void	quit(t_info *info)
{
	sem_close(info->death);
	sem_close(info->stop);
	sem_close(info->messages);	
	sem_close(info->forks);
}
