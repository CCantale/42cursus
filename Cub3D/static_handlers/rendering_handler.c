/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:52:16 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 20:18:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering_handler.h"

static void	cub_pixel_put(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_size + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	init_image(t_image *image)
{
	if (!image->image)
	{
		image->image = mlx_new_image(
				get_game_init(),
				WINDOW_WIDTH, WINDOW_HEIGHT
				);
		image->addr = mlx_get_data_addr(
				image->image,
				&image->bits_per_pixel,
				&image->line_size,
				&image->endian);
	}
}

static void	rendering_handler(int x, int y, int color, t_render option)
{
	static t_image	image_one;
	static t_image	image_two;
	static short	switch_var;
	t_image			*buffer_img;

	if (switch_var == 0)
		buffer_img = &image_one;
	if (switch_var == 1)
		buffer_img = &image_two;
	init_image(&image_one);
	init_image(&image_two);
	if (option == ren_PIXEL_PUT)
		cub_pixel_put(buffer_img, x, y, color);
	if (option == ren_RENDER)
	{
		draw_pixels();
		mlx_put_image_to_window(get_game_init(), get_window(),
			buffer_img->image, 0, 0);
		switch_var = (switch_var - 1) * -1;
	}
}

void	draw_pixel(int x, int y, int color)
{
	rendering_handler(x, y, color, ren_PIXEL_PUT);
}

void	render(void)
{
	rendering_handler(0, 0, 0, ren_RENDER);
}
