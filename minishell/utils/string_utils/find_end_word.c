/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_end_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:38:45 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:38:46 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

size_t	ft_word_len(char *word)
{
	size_t	i;

	i = 0;
	while (word[i])
	{
		if (char_is_alpha(word[i]) == 0)
			return (i);
		++i;
	}
	return (i);
}
