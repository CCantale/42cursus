/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:50:25 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/16 22:02:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	void	*map;

	if (count == 0 || size == 0)
		return (NULL);
	map = (void *)malloc(sizeof(size) * count);
	if (map == 0)
		return (NULL);
	i = 0;
	while (i++ < size * count)
		*(map + i) = 0;
	return (map);
}
