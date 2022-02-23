/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:50:25 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/22 17:39:48 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*map;

	map = (void *)malloc(count * size);
	if (!map)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		*((char *)map + i) = 0;
		++i;
	}
	return (map);
}
