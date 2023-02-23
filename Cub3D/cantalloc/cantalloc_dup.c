/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cantalloc_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:36:40 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 16:00:46 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cantalloc.h"

static size_t	cantalloc_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*cantalloc_dup(char *str)
{
	char	*dup;
	size_t	i;

	dup = cantalloc(sizeof(char) * (cantalloc_len(str) + 1));
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		++i;
	}
	dup[i] = 0;
	return (dup);
}
