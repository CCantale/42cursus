/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:23:26 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/24 06:00:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char	**split)
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

static size_t	how_many(const char *s, char c)
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

static char	*stringify(const char *s, size_t beg, size_t end, char **split)
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
	size_t	i[2];
	char	**split;

	if (!s)
		return (NULL);
	split = ft_calloc(how_many(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	ft_bzero(i, sizeof(size_t) * 2);
	flag = -1;
	while (i[1] < how_many(s, c))
	{
		if (*(s + i[0]) != c && flag < 0)
			flag = i[0];
		if (flag >= 0 && (*(s + i[0]) == c || !*(s + i[0])))
		{
			*(split + i[1]) = stringify(s, flag, i[0], split);
			if (!*(split + i[1]++))
				return (NULL);
			flag = -1;
		}
		++i[0];
	}
	return (split);
}
