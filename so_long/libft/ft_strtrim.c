/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:27:34 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/21 18:18:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	size_t	i;

	if (!set)
		return (0);
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

	if (!s1)
		return (NULL);
	i = 0;
	while (*(s1 + i) && check_set(*(s1 + i), set))
		++i;
	if (!*(s1 + i))
		return (ft_calloc(1, 1));
	j = ft_strlen(s1) - 1;
	while (j > i && check_set(*(s1 + j), set))
		--j;
	++j;
	trim = ft_calloc(j - i + 1, sizeof(char));
	if (!trim)
		return (NULL);
	while (i < j)
	{
		--j;
		*(trim + j - i) = *(s1 + j);
	}
	return (trim);
}
