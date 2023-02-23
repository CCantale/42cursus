/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:32:02 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 15:57:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	cub_strlen(char	*str);
/* end of declarations */

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
