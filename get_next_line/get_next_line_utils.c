/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:48:11 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/27 23:42:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, size_t *count)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '\n')
		{
			*count = i;
			return ((char *)s + i);
		}
		++i;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	if (s1)
		while (*(s1 + i))
			++i;
	j = 0;
	while (*(s2 + j))
		++j;
	join = (char *)malloc(sizeof(char) * i + j + 1);
	if (!join)
		return (NULL);
	*(join + i + j) = '\0';
	while (--j >= 0)
		*(join + i + j) = *(s2 + j);
	while (--i >= 0)
		*(join + i) = *(s1 + i);
	free(s1);
	return (join);
}
