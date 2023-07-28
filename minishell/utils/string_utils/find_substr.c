/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:35:32 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/23 19:46:25 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

char	*ft_substr(char *str, char delimiter)
{
	char	*substr;
	size_t	len_substr;

	substr = NULL;
	len_substr = 0;
	while (str[len_substr])
	{
		if (str[len_substr] == delimiter)
			break ;
		len_substr++;
	}
	if (len_substr == 0)
		return (NULL);
	substr = ft_strcpy(substr, str, len_substr);
	return (substr);
}

char	*find_substr(char *str, char *substr)
{
	char	*str_tmp;
	int		idx_substr;

	if (!str)
		return (NULL);
	while (*str)
	{
		str_tmp = str;
		idx_substr = 0;
		while (*str_tmp == substr[idx_substr]
			&& substr[idx_substr])
		{
			str_tmp++;
			idx_substr++;
		}
		if (substr[idx_substr] == '\0')
			return (str);
		else
			str++;
	}
	return (NULL);
}

t_bool	str_not_empty(char *str)
{
	if (!str)
		return (e_false);
	while (*str)
	{
		if (e_false == ft_isspace(*str)
			&& *str != '\''
			&& *str != '"')
			return (e_true);
		str++;
	}
	return (e_false);
}
