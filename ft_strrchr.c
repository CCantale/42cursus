/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:23:34 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/20 11:42:24 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*str;

	str = s;
	i = 0;
	while (*(str + i))
		++i;
	if (c == 0)
		return ((char *)str + i);
	while (i >= 0)
	{
		if (*(str + i) == (char)c)
			return ((char *)str + i);
		--i;
	}
	return (NULL);
}
