/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:13:04 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/24 05:48:05 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1)
		return (NULL);
	i = 0;
	while (*(s1 + i))
		++i;
	j = 0;
	while (*(s2 + j))
		++j;
	join = (char *)malloc(sizeof(char) * i + j + 1);
	if (!join)
		return (NULL);
	*(join + i + j) = '\0';
	while (--j >= 0)
		*(join + i + j) = *(s2 + j);
	while (--i >= 0)
		*(join + i) = *(s1 + i);
	return (join);
}	
