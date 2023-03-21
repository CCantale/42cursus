/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_handlers_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:41:45 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 20:14:25 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "static_handlers_init.h"

static int	is_map_start(char *current_line)
{
	size_t	i;

	i = 0;
	while (current_line[i])
	{
		if (current_line[i] != '1' && current_line[i] != ' ')
			return (NOT_OK);
		++i;
	}
	return (OK);
}

int	static_handlers_init(char **input)
{
	size_t	i;

	if (!input)
		return (NOT_OK);
	if (new_textures(input) == NOT_OK)
		return (NOT_OK);
	i = 0;
	while (is_map_start(input[i]) == NOT_OK)
			++i;
	if (i > 6)
		return (error_msg("Too many parameters."));
	if (update_map(input + i) == NOT_OK)
		return (NOT_OK);
	return (OK);
}
