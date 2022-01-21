/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:32:10 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/20 23:59:10 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (*(s1 + i))
		++i;
	s2 = (char *)malloc(sizeof(char) * i + 1);
	if (!s2)
		return (NULL);
	while (i-- > 0)
		*(s2 + i) = *(s1 + i);
	return (s2);
}
