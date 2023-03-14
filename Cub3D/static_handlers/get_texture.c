/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:38:53 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/14 19:01:21 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_handler.h"

t_image	*texture_handler(char **new_set, int option);
/* end of declarations */

t_image	*get_north_texture(void)
{
	return (texture_handler(NULL, tex_GET_NORTH));
}

t_image	*get_south_texture(void)
{
	return (texture_handler(NULL, tex_GET_SOUTH));
}

t_image	*get_west_texture(void)
{
	return (texture_handler(NULL, tex_GET_WEST));
}

t_image	*get_east_texture(void)
{
	return (texture_handler(NULL, tex_GET_EAST));
}
