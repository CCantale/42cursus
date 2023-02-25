/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:26:42 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 04:07:10 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "join.h"
					#include <stdio.h>

char	*cub_join(char *s1, char *s2, bool free1, bool free2)
{
	char	*ret;

	ret = NULL;
	if (!s1 && free2 == false)
	{
		s2 = cub_strdup(s2);
		if (!s2)
			return (error_null("cub_join() malloc error"));
		free2 = true;
	}
	ret = cub_calloc(cub_strlen(s1) + cub_strlen(s2) + 1, sizeof(char));
	if (!ret)
		error_null("cub_join() malloc error");
	else
	{
		ret = cub_strncpy(ret, s1, cub_strlen(s1));
		ret = cub_strncpy(ret + cub_strlen(ret), s2, cub_strlen(s2));
		ret -= cub_strlen(s1);
	}
	if (s1 && free1 == true)
		free(s1);
	if (s2 && free2 == true)
		free(s2);
	return (ret);
}
