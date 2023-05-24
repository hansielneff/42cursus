/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:51:58 by helneff           #+#    #+#             */
/*   Updated: 2023/05/03 16:33:27 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <mlx.h>

#include "image.h"

int	init_image(t_image *img, const t_window *window)
{
	img->mlx_img = mlx_new_image(window->mlx_ptr,
			window->width, window->height);
	if (img->mlx_img == NULL)
		return (-1);
	img->buffer = mlx_get_data_addr(
			img->mlx_img, &img->pixel_bits, &img->line_bytes, &img->endian);
	img->width = window->width;
	img->height = window->height;
	return (0);
}

void	set_pixel(t_image *img, int x, int y, int color)
{
	const int	pixel = (y * img->line_bytes) + (x * 4);

	if (img->endian == 1)
	{
		img->buffer[pixel + 0] = (color >> 24);
		img->buffer[pixel + 1] = (color >> 16) & 0xFF;
		img->buffer[pixel + 2] = (color >> 8) & 0xFF;
		img->buffer[pixel + 3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		img->buffer[pixel + 0] = (color) & 0xFF;
		img->buffer[pixel + 1] = (color >> 8) & 0xFF;
		img->buffer[pixel + 2] = (color >> 16) & 0xFF;
		img->buffer[pixel + 3] = (color >> 24);
	}
}

void	fill_color(t_image *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
			set_pixel(img, x++, y, color);
		y++;
	}
}
