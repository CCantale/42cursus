/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:28:20 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/16 12:29:06 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *path, char *ending)
{
	int	i;
	int	j;

	i = 0;
	while (path[i])
	{
		j = 0;
		while (ending[j] && path[i] == ending[j])
		{
			++j;
			++i;
		}
		if (path[i] == 0 && ending[j] == 0)
			return (1);
		if (path[i])
			++i;
	}
	return (0);
}
