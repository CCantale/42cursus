/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:15:58 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/19 13:57:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char	**split, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
		free(*(split + i++));
	free(split);
}

void	ft_strncopy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = 0;
}

void	how_many_words(char const *s, size_t *count, char c)
{
	size_t	i;

	*count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c && *(s + i - 1) && *(s + i))
			++*count;
		++i;
	}
}

void	*str_alloc(char **split, size_t i, size_t count, size_t word)
{
	*(split + word) = (char *)malloc(sizeof(char) * i - count + 1);
	if (!*(split + word))
	{
		free_split(split, word - 1);
		return (NULL);
	}
	return (*(split + word));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	word;
	char	**split;

	how_many_words(s, &count, c);
	split = (char **)malloc(sizeof(char *) * count + 2);
	if (!split)
		return (NULL);
	word = 0;
	count = 0;
	i = 0;
	while (*(s + i - 1))
	{
		if (*(s + i) == c || *(s + i) == 0)
		{
			if (!str_alloc(split, i, count, word))
				return (NULL);
			ft_strncopy(*(split + word++), s + count, i - count);
			count = i + 1;
		}
		++i;
	}
	*(split + word) = 0;
	return (split);
}
