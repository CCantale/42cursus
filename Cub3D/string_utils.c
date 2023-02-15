/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:46:00 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/15 18:26:49 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

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

char	*cub_strdup(char *str)
{
	char	*dup;
	size_t	i;

	dup = malloc(sizeof(char) * (cub_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		++i;
	}
	dup[i] = 0;
	return (dup);
}

/* copies the specified nbr of bytes and null-terminates right after */
char	*cub_strncpy(char *dest, char *src, size_t bytes)
{
	size_t	i;

	if (!dest)
		return (src);
	if (!src)
		return (dest);
	i = 0;
	while (src[i] && i < bytes)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}

char	*cub_join(char *s1, char *s2, bool free1, bool free2)
{
	char	*ret;

	ret = cub_calloc(sizeof(char) * (cub_strlen(s1) + cub_strlen(s2) + 1));
	if (!ret)
	{
		error_msg("cub_join() malloc error");
		return (NULL);
	}
	if (!s1 && free2 == false)
	{
		s2 = cub_strdup(s2);
	}
	ret = cub_strncpy(ret, s1, cub_strlen(s1));
	ret = cub_strncpy(ret + cub_strlen(ret), s2, cub_strlen(s2));
	ret -= cub_strlen(s1);
	if (s1 && free1 == true)
		free(s1);
	if (s2 && free2 == true)
		free(s2);
	return (ret);
}
