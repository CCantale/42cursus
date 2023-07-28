/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psycho_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:03:44 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:04:12 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

char	*splitcpy(char const *str, int *j, char delimiter)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != delimiter && str[i] != 0)
		++i;
	*j += i + 1;
	new_str = ft_malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != delimiter && str[i] != 0)
	{
		new_str[i] = str[i];
		++i;
	}
	new_str[i] = 0;
	return (new_str);
}

int	split_count(char *str, char delimiter)
{
	int	i;
	int	lines;

	lines = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == delimiter)
			++lines;
		++i;
	}
	return (lines);
}

char	**dp_split(char const *str, char delimiter)
{
	int		i;
	int		j;
	int		lines;
	char	**split;

	if (!str)
		return (NULL);
		lines = split_count((char *)str, delimiter);
	split = ft_malloc(sizeof(char *) * (lines + 1));
	split[lines] = 0;
	i = 0;
	j = 0;
	while (i < lines)
	{
		split[i] = splitcpy(&str[j], &j, delimiter);
		++i;
	}
	return (split);
}
