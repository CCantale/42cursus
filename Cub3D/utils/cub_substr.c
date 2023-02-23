/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:32:37 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 14:35:03 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substr.h"

char	*cub_substr(char *str, size_t start, size_t end)
{
	char	*substring;
	size_t	i;

	substring = cantalloc(sizeof(char) * (end - start + 2));
	if (!substring)
	{
		return (error_null("Malloc error."));
	}
	i = 0;
	while (start <= end)
	{
		substring[i] = str[start];
		++start;
		++i;
	}
	substring[i] = 0;
	return (substring);
}
