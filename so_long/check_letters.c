/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:44:10 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/16 13:52:07 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_letters(char *str)
{
	int		i;
	int		j;
	int		flag;
	char	*set;

	set = malloc(sizeof(char) * 8);
	ft_strlcpy(set, "PCEN01\n", 8);
	i = 0;
	while (str[i])
	{
		j = 0;
		flag = 0;
		while (set[j])
			if (str[i] == set[j++])
					flag = 1;
		if (flag == 0)
		{
			free(set);
			free(str);
			return (0);
		}
		++i;
	}
	free(set);
	return (1);
}
