/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:38:53 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/13 07:11:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_handler.h"

char	*texture_handler(char **new_set, int option);
/* end of declarations */

char	*get_north_texture(void)
{
	return (texture_handler(NULL, tex_GET_NORTH));
}

char	*get_south_texture(void)
{
	return (texture_handler(NULL, tex_GET_SOUTH));
}

char	*get_west_texture(void)
{
	return (texture_handler(NULL, tex_GET_WEST));
}

char	*get_east_texture(void)
{
	return (texture_handler(NULL, tex_GET_EAST));
}
