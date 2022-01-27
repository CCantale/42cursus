/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:34:22 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/27 23:43:15 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static char	*get_line(char *store, size_t line_size)
{
	size_t	i;
	char	*line;
	char	*memories;
	char	*needle;

	line = (char *)malloc(sizeof(char) * (line_size + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (store[i] != '\n')
	{
		line[i] = store[i];
		++i;
	}
	line[i] = '\n';
	line[i + 1] = 0;
	needle = store + i;
	while (store[i])
		++i;
	memories = (char *)malloc(sizeof(char) * (i - line_size + 1));
	if (!memories)
	{
		free(line);
		return (NULL);
	}
	while (store + i != needle)
	{
		memories[i - line_size] = store[i];
	   --i;
  	}
	free(store);
	store = memories;
	return (line);
}

char	*get_next_line(int fd)
{
	size_t		i;
	char		*needle;
	char		*buffer;
	char		*line;
	static char	*store;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	needle = 0;
	if (read(fd, buffer, BUFFER_SIZE) < 0)
		return (NULL);
	store = ft_strjoin(store, buffer);
	needle = ft_strchr(store, &i);
	if (!needle)
		line = get_next_line(fd);
	line = get_line(store, i + 1);
	return (line);
}

int	main(void)
{
	char	*line;
	
	line = get_next_line(0);
	printf("%s", line);
	return (0);
}


