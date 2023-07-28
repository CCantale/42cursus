/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:12:11 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/23 17:15:28 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *buf, char *src, int copy_len)
{
	int	i;

	if (!buf)
	{
		buf = (char *) malloc((copy_len + 1) * sizeof(char));
		buf[copy_len] = '\0';
	}
	i = 0;
	while (i < copy_len)
	{
		buf[i] = src[i];
		i++;
	}
	return (buf);
}
