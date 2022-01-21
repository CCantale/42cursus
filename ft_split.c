/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:23:26 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/21 18:28:41 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char	**split)
{
	size_t	i;

	i = 0;
	while (*(split + i))
	{
		free(*(split + i));
		++i;
	}
	free(split);
}

size_t	how_many(const char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c && (*(s + i + 1) == c || !*(s + i + 1)))
			++count;
		++i;
	}
	return (count);
}

char	*stringify(const char *s, size_t beg, size_t end, char **split)
{
	char	*string;

	string = ft_calloc(end - beg + 1, sizeof(char));
	if (!string)
	{
		free_split(split);
		return (NULL);
	}
	ft_strlcpy(string, s + beg, end - beg + 1);
	return (string);
}

char	**ft_split(char const *s, char c)
{
	int		flag;
	size_t	i;
	size_t	j;
	char	**split;

	split = ft_calloc(how_many(s, c) + 1, sizeof(char *));
	if (!split || !s)
		return (NULL);
	i = 0;
	j = 0;
	flag = -1;
	while (j < how_many(s, c))
	{
		if (*(s + i) != c && flag < 0)
			flag = i;
		if (flag >= 0 && (*(s + i) == c || !*(s + i)))
		{
			*(split + j) = stringify(s, flag, i, split);
			if (!*(split + j++))
				return (NULL);
			flag = -1;
		}
		++i;
	}
	return (split);
}
