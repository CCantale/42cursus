/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:02:31 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/14 19:04:07 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_STRUCT_H
# define IMAGE_STRUCT_H

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_image;

#endif
