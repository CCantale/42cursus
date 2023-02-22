/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:10:54 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/15 18:14:09 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*cub_calloc(size_t quantity, size_t size)
{
	char	*ret;
	size_t	i;

	ret = malloc(quantity * size);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < quantity * size)
	{
		ret[i] = 0;
		++i;
	}
	return ((void *)ret);
}
