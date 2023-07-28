/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:23:33 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/10 12:23:33 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = ft_malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		++i;
	}
	new_str[i] = 0;
	return (new_str);
}

void	ft_str_replace(char **str, char *new)
{
	ft_free(*str);
	*str = ft_strdup(new);
}
