/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:38:53 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/24 18:20:08 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_handler.h"

void	*texture_handler(char **new_set, int option);
/* end of declarations */

void	*get_north_texture(void)
{
	return (texture_handler(NULL, tex_GET_NORTH));
}

void	*get_south_texture(void)
{
	return (texture_handler(NULL, tex_GET_SOUTH));
}

void	*get_west_texture(void)
{
	return (texture_handler(NULL, tex_GET_WEST));
}

void	*get_east_texture(void)
{
	return (texture_handler(NULL, tex_GET_EAST));
}
