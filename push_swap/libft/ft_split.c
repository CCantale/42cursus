/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:23:26 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/06 18:09:36 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
	return (NULL);
}

static char	**ft_realloc_split(char **split, int len)
{
	int		i;
	char	**new_split;

	new_split = ft_calloc(len + 1, sizeof(char **));
	if (!new_split)
	{
		free_split(split);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_split[i] = split[i];
		++i;
	}
	if (split)
		free(split);
	new_split[i] = NULL;
	return (new_split);
}

static char	**allocate_and_copy(char **split, char const *start, int length, int *r)
{
	int	row;
	
	row = *r;
	split = ft_realloc_split(split, row);
	if(!split)
		return (free_split(split));
	split[row] = malloc(sizeof(char) * (length));
	if(!split[row])
		return (free_split(split));
	ft_strlcpy(split[row], start, length);
	*r += 1;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		beg;
	int		end;
	int		row;
	char	**split;

	split = 0;
	row = 0;
	beg = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] == c)
		{
			split = allocate_and_copy(split, s + beg, end - beg + 1, &row);
			if (!split)
				return (NULL);
			beg = end + 1;
		}
		++end;
	}
	if (s[end - 1] != c)
		split = allocate_and_copy(split, s + beg, end - beg + 1, &row);
	if (!split)
		return (NULL);
	return (ft_realloc_split(split, row));
}

