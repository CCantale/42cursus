/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_strip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:14:45 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/19 19:14:45 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	str_number_occurrences(char *str, char c)
{
	int	occurrences;

	if (!str)
		return (0);
	if (c == '\0')
		return (1);
	occurrences = 0;
	while (*str)
	{
		if (*str == c)
			occurrences++;
		str++;
	}
	return (occurrences);
}

char	*string_strip(char *str, char to_strip, t_bool free_input)
{
	char	*stripped;
	int		occurrences;
	int		idx_stripped;
	int		idx_input;

	if (!str)
		return (NULL);
	occurrences = str_number_occurrences(str, to_strip);
	stripped = (char *) malloc(
			(ft_strlen(str) - occurrences + 1) * sizeof(char));
	idx_stripped = 0;
	idx_input = 0;
	while (idx_input < (int)ft_strlen(str))
	{
		if (str[idx_input] != to_strip)
		{
			stripped[idx_stripped] = str[idx_input];
			idx_stripped++;
		}
		idx_input++;
	}
	if (free_input && str)
		free(str);
	stripped[idx_stripped] = '\0';
	return (stripped);
}
