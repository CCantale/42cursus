/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 06:51:38 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/29 21:45:13 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*find_moment(char *memory)
{
	size_t	i;

	if (!memory)
		return (NULL);
	i = 0;
	while (memory[i])
	{
		if (memory[i] == '\n')
			return (memory + i);
		++i;
	}
	return (NULL);
}

char	*make_connections(char *memory, char *remembrance)
{
	int		i;
	int		j;
	char	*clear_thought;

	if (!memory && (!remembrance || !*remembrance))
		return (NULL);
	i = 0;
	if (memory)
		while (memory[i])
			++i;
	j = 0;
	while (remembrance[j])
		++j;
	clear_thought = (char *)malloc(sizeof(char) * i + j + 1);
	if (!clear_thought)
		return (NULL);
	clear_thought[i + j] = '\0';
	while (--j >= 0)
		clear_thought[i + j] = remembrance[j];
	while (--i >= 0)
		clear_thought[i] = memory[i];
	free(memory);
	return (clear_thought);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*map;

	map = (void *)malloc(count * size);
	if (!map)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		*((char *)map + i) = 0;
		++i;
	}
	return (map);
}
