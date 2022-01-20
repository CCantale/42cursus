/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:27:34 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/20 13:37:06 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (c == *(set + i))
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trim;

	i = 0;
	while (*(s1 + i) && check_set(*(s1 + i), set))
		++i;
	j = 0;
	while (*(s1 + j + 1))
		++j;
	while (j > i && check_set(*(s1 + j), set))
		--j;
	trim = (char *)malloc(sizeof(char) * j - i + 1);
	if (!trim)
		return (NULL);
	++j;
	*(trim + j - i) = 0;
	while (i < j)
	{
		--j;
		*(trim + j - i) = *(s1 + j);
	}
	return (trim);
}
