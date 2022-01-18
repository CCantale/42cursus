/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:15:58 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/18 15:35:03 by ccantale         ###   ########.fr       */
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

void	ft_strncopy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*(src + i) != '\0')
			*(dest + i) = *(src + i);
		else
			*(dest + i) = '\0';
		++i;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	word;
	char	**split;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c && *(s + i - 1) && *(s + i))
			++count;
		++i;
	}
	split = (char **)malloc(sizeof(char *) * count + 2);
	if (!split)
		return (NULL);
	word = 0;
	count = 0;
	i = 0;
	while (*(s + ++i))
		if (*(s + i) == c)
		{
			*(split + word) = (char *)malloc(sizeof(char) * i - count);
			if (!*(split + word))
			{
				free_split(split, word - 1);
				return (NULL);
			}
			ft_strncopy(*(split + word++), s + count, i - count - 1); 
			count = i;
		}
	*(split + word) = 0;
	return (split);
}
