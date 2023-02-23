/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_strncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:32:28 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 15:58:21 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* copies the specified nbr of bytes and null-terminates right after */
char	*cub_strncpy(char *dest, char *src, size_t bytes)
{
	size_t	i;

	if (!dest)
		return (src);
	if (!src)
		return (dest);
	i = 0;
	while (src[i] && i < bytes)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}
