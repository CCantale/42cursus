/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitariianism.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:30:42 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/14 21:14:38 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utilitarianism.h"

int	phi_atoi(char *info)
{
	int		i;
	long	result;

	result = 0;
	i = 0;
	if (info[i] == '-')
		return (mistake(" You're being too negative here. Ok, listen,\n"
					" from now on, I want ALL your arguments to be positive.\n"
					" Trust me, it's life changing!\"\n"));
	while (info[i])
	{
		if (info[i] >= '0' && info[i] <= '9')
		{
			result *= 10;
			result += info[i] - '0';
		}
		else
			return(mistake(" Words are important, it's true, but not this"
						" time,\n I'm afraid. Remember that all reality is"
						" made of nothing but numbers\"\n"));
	}
	if (result > 2147483647)
		return (mistake(" It's good to dream big, but this time here\n"
					" try and keep your arguments smaller\"\n"));
	return ((int)result);
}
