/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:27:34 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/18 13:09:17 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
		if (c == *(set + i++))
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trim;

	i = 0;
	while (check_set(*(s1 + i), set))
		++i;
	j = i;
	while (!check_set(*(s1 + j), set))
		++j;
	trim = (char *)malloc(sizeof(char) * j - i + 1);
	if (!trim)
		return (NULL);
	*(trim + j - i) = 0;
	while (i <= j--)
		*(trim + j - i) = *(s1 + j);
	return (trim);
}
