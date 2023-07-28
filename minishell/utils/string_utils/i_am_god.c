/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_god.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:29:43 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:45:02 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != 0)
		i++;
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	while ((*s != '\0') && (*s != ch))
	{
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return ((char *) NULL);
}

char	*justice(char *str, t_bool opcode)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strchr(str, ' ');
	if (opcode == e_false)
	{
		if (ret == NULL)
			return (NULL);
		return (ft_strjoin(ft_strdup(ret), " ", e_true, e_false));
	}
	else
	{
		if (ret == NULL)
			return (str);
		i = ret - str;
		ret = malloc(i + 1);
		ret[i] = 0;
		ft_strlcpy(ret, str, i + 1);
		return (ret);
	}
}
