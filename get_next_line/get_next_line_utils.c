/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:48:11 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/28 04:19:09 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
