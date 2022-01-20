/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:09:35 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/20 13:00:20 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	i = 0;
	while (*(s + i))
		++i;
	if (start > (size_t)i)
		return (ft_calloc(1, 1));
	i = 0;
	while (*(s + start + i) && (size_t)i < len)
		++i;
	substr = (char *)malloc(sizeof(char) * i + 1);
	if (!substr)
		return (NULL);
	*(substr + i) = '\0';
	while (i > 0)
	{
		--i;
		*(substr + i) = *(s + start + i);
	}
	return (substr);
}
