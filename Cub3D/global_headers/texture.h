/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:23:25 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/13 03:27:11 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

int		new_textures(char **new_set);
char	*get_north_texture(void);
char	*get_south_texture(void);
char	*get_west_texture(void);
char	*get_east_texture(void);
void	destroy_textures(void);

#endif
