/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:59:55 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/20 11:58:17 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest,
		const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	j = 0;
	while (*(src + j))
		++j;
	src_length = j;
	if (dstsize == 0)
		return (src_length);
	i = 0;
	while (*(dest + i))
		++i;
	dest_length = i;
	j = 0;
	while (*(src + j) && i + j < dstsize - 1)
	{
		*(dest + i + j) = *(src + j);
		++j;
	}
	if (dstsize < dest_length)
		dest_length = dstsize;
	if (dstsize != 0 && i + j != dstsize)
		*(dest + i + j) = '\0';
	return (dest_length + src_length);
}
