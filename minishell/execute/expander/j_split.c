/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:08:47 by mruizzo           #+#    #+#             */
/*   Updated: 2022/12/03 20:31:45 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*ft_malloc_strcpy(const char *s, int n)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((n + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < n && s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	quote_str(const char *s)
{
	int	i;
	int	flag;

	i = 0;
	if (s[i] == 34 || s[i] == 39)
	{
		if (s[i] == 34)
			flag = 34;
		else if (s[i] == 39)
			flag = 39;
		i++;
		while (s[i])
		{
			if (s[i] == flag)
				return (i + 1);
			i++;
		}
	}
	return (0);
}

int	ft_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if (quote_str(s + i) > 0)
			i += quote_str(s + i);
		else
			i++;
	}
	return (i);
}

int	ft_find_size(const char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (*s)
	{
		i = ft_len(s, c);
		if (i)
			x++;
		s += i;
		if (*s == c)
			s++;
	}
	return (x);
}

char	**j_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**dst;
	int		size;

	i = 0;
	x = -1;
	if (s == NULL)
		return (NULL);
	size = ft_find_size(s, c);
	dst = malloc((size + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	while (++x < size)
	{
		while (*s == c)
			s++;
		i = ft_len(s, c);
		if (i != 0)
			dst[x] = ft_malloc_strcpy(s, i);
		s += i;
	}
	dst[size] = 0;
	return (dst);
}
