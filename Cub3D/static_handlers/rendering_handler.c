/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:52:16 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/09 20:02:50 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering_handler.h"

static void	rendering_handler(t_render option/*vediamo che metterci*/)
{
	static t_image	image_one;
	static t_image	image_two;
	static			switch_var;

	if (option == ren_PIXEL_PUT)
	{
		cub_puxel_put(/*le cose che gli passo*/);
	}
	if (oprion == ren_RENDER)
	{
		if (switch_var == 0)
			render(image_one);
		if (switch_var == 1)
			render(image_two);
