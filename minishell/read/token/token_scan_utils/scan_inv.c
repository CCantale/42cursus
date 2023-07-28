/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_inv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:04:38 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/11 16:47:36 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize.h"

size_t	scan_spaces(char *str, size_t offset)
{
	int	index;

	index = offset;
	while (e_true == ft_isspace(str[index]))
		index++;
	return (index);
}

size_t	scan_inv_quotes(char *str, size_t offset)
{
	int	index;

	index = offset;
	while (str[index] == '"' || str[index] == '\'')
	{
		if (str[index + 1] != str[index])
			break ;
		index += 2;
	}
	return (index);
}

size_t	scan_invariants(char *str, size_t offset)
{
	size_t	new_offset;

	new_offset = scan_spaces(str, offset);
	new_offset = scan_inv_quotes(str, new_offset);
	return (new_offset);
}

size_t	occ_outside_quotes(char *str, char to_count)
{
	size_t	occurrences;
	size_t	i;
	char	quote;

	if (str == NULL)
		return (0);
	quote = '\0';
	occurrences = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == to_count && quote == '\0')
			|| (str[i] == to_count && quote == to_count))
			occurrences++;
		if (ft_is_quote(str[i]))
		{
			if (quote && str[i] == quote)
				quote = '\0';
			else if (quote == '\0')
				quote = str[i];
		}
		i++;
	}
	return (occurrences);
}
