/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:23:26 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/08 17:38:04 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**free_split(char **split, int row)
{
	int	i;

	i = 0;
	while (i < row)
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

	new_split = ft_calloc(len + 1, sizeof(char *));
	if (!new_split)
	{
		if (split)
			free_split(split, len);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_split[i] = split[i];
		++i;
	}
	free(split);
	return (new_split);
}

static char	**allocate_and_copy(char **split, char const *start, int length, int *r)
{
	int	row;
	
	if (*start == '\n')
		return (split);
	row = *r;
	split = ft_realloc_split(split, row);
	if(!split)
		return (NULL);
	split[row] = malloc(sizeof(char) * (length));
	if(!split[row])
		return (free_split(split, row));
	ft_strlcpy(split[row], start, length);
	*r += 1;
	return (split);
}

char	**split_nl(const char *s)
{
	int		beg;
	int		end;
	int		row;
	char	**split;

	split = NULL;
	row = 0;
	beg = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] == '\n')
		{
			split = allocate_and_copy(split, s + beg, end - beg + 1, &row);
			if (!split)
				return (NULL);
			beg = end + 1;
		}
		++end;
	}
	if (s[end - 1] != '\n')
		split = allocate_and_copy(split, s + beg, end - beg + 1, &row);
	if (!split)
		return (NULL);
	return (ft_realloc_split(split, row));
}

