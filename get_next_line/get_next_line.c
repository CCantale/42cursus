/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:34:22 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/27 18:59:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t 		i;
	char		*needle;
	char		*buffer;
	static char	*store;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer || !read(fd, buffer, BUFFER_SIZE) || buffer == -1)
		return (NULL);
	needle = ft_strchr(buffer, '\n');
	if (!needle)
		continue ;
	else
		break ;

}
