/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:21:36 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/09 18:32:25 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

size_t	skip_consecutive_chars(char *string, size_t offset,
			char to_skip, int direction)
{
	while (string[offset] == to_skip
		&& e_false == (offset == 0 && direction == -1))
		offset += direction;
	return (offset);
}

size_t	skip_past_char(char *str, size_t offset,
			char to_skip, int direction)
{
	int	i;

	i = offset;
	while (e_true)
	{
		if ((i == 0 && direction == -1)
			|| (str[i] == '\0' && direction == 1))
			return (i);
		if (str[i] == to_skip)
			return (i + direction);
		i += direction;
	}
	return (offset);
}

size_t	scroll_to_char(char *str, char ch)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (i);
		++i;
	}
	return (0);
}
