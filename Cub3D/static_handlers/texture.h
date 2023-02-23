/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:23:25 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 15:42:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

int		new_textures(char **new_set);
void	*get_north_texture(void);
void	*get_south_texture(void);
void	*get_west_texture(void);
void	*get_east_texture(void);
void	*get_floor_texture(void);

#endif
