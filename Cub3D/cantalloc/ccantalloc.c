/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccantalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:47:54 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 00:50:49 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cantalloc.h"

void	*ccantalloc(size_t size, size_t count)
{
	char	*new_ptr;
	size_t	i;

	new_ptr = cantalloc(size * count);
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		new_ptr[i] = 0;
		++i;
	}
	return ((void *)new_ptr);
}
