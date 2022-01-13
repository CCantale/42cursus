/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:29:35 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/13 15:38:23 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dest, char *restrict src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
	{
		while (*(src + i))
			++i;
		return (i);
	}
	else
	{
		while (i < (size - 1) && *(src + i))
		{
			*(dest + i) = *(src + i);
			++i;
		}
	}
	*(dest + i) = '\0';
	return (i);
}
