/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 06:35:52 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/29 22:06:38 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_your_mind(char **memory)
{
	size_t	i;

	i = 0;
	while (i < 1025)
	{
		free(memory[i]);
		++i;
	}
	free(memory);
}

static char	*get_memory(int past, char *memory)
{
	char	*remembrance;
	int		moments;

	remembrance = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!remembrance)
		return (NULL);
	moments = 1;
	while (!find_moment(memory) && moments != 0)
	{
		moments = read(past, remembrance, BUFFER_SIZE);
		if (moments < 0)
		{
			free(remembrance);
			return (NULL);
		}
		remembrance[moments] = 0;
		memory = make_connections(memory, remembrance);
	}
	free(remembrance);
	return (memory);
}

static char	*get_yourself_together(char *memory)
{
	size_t	i;
	char	*yourself;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		++i;
	yourself = (char *)malloc(sizeof(char) * (i + 2));
	if (!yourself)
		return (NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
	{
		yourself[i] = memory[i];
		++i;
	}
	if (memory[i] == '\n')
	{
		yourself[i] = '\n';
		++i;
	}
	yourself[i] = 0;
	return (yourself);
}

static char	*for_get_something(char *memory)
{
	size_t	i;
	size_t	j;
	char	*whats_left;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		++i;
	if (!memory[i])
	{
		free(memory);
		return (NULL);
	}
	j = 0;
	while (memory[j])
		++j;
	whats_left = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!whats_left)
		return (NULL);
	++i;
	j = 0;
	while (memory[i])
		whats_left[j++] = memory[i++];
	whats_left[j] = 0;
	free(memory);
	return (whats_left);
}

char	*get_next_line(int fd)
{
	char		*yourself;
	static char	**memory;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory = ft_calloc(1025, sizeof(char *));
	if (!memory)
		return (NULL);
	memory[fd] = get_memory(fd, memory[fd]);
	if (!memory[fd])
	{
		free(memory[fd]);
		free_your_mind(memory);
		return (NULL);
	}
	yourself = get_yourself_together(memory[fd]);
	memory[fd] = for_get_something(memory[fd]);
	if (!find_moment(yourself))
		free(memory[fd]);
	free_your_mind(memory);
	return (yourself);
}
