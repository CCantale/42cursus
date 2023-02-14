/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:46:00 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/14 22:01:39 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

size_t	cub_strlen(char	*str)
{
	size_t	i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

/* copies and null-terminates */
char	*cub_strncpy(char *dest, char *src, size_t bytes)
{
	size_t	i;

	if (!dest)
		return (src);
	i = 0;
	while (src[i] && i < bytes)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return (dest);
}

char	*cub_join(char *s1, char *s2, bool free1, bool free2)
{
	char	*ret;

	ret = mallloc(sizeof(char) * (cub_strlen(s1) + cub_strlen(s2) + 1));
	if (!ret)
	{
		error_msg("cub_join() malloc error");
		return (NULL);
	}
	ret = cub_strncpy(ret, s1, cub_strlen(s1));
	ret = cub_strncpy(ret + cub_strlen(ret), s2, cub_strlen(s2));
	if (free1 == true)
		free(s1);
	if (free2 == true)
		free(s2);
	return (ret);
}
