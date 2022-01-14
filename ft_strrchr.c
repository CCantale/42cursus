/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:23:34 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/15 00:53:37 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*(str++))
	{
	}
	if (c == 0)
		return ((char *)str);
	while (str-- != s)
		if (*(str) == (char)c)
			return ((char *)str);
	return (NULL);
}
