/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:23:25 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/14 19:16:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "image_struct.h"

int		new_textures(char **new_set);
t_image	*get_north_texture(void);
t_image	*get_south_texture(void);
t_image	*get_west_texture(void);
t_image	*get_east_texture(void);

#endif
