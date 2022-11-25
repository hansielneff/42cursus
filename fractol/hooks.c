/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:24:43 by helneff           #+#    #+#             */
/*   Updated: 2022/11/24 14:50:28 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "libft.h"

#include <mlx.h>

int	key_hook(int keycode, void *param)
{
	t_hook_params	*args;
	double			move_step;

	args = param;
	move_step = 0.1 / args->zoom;
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		args->pos_x -= move_step;
	else if (keycode == 124)
		args->pos_x += move_step;
	else if (keycode == 125)
		args->pos_y += move_step;
	else if (keycode == 126)
		args->pos_y -= move_step;
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_hook_params	*args;
	const double	zoom_rate = 1.5;

	(void)x;
	(void)y;
	args = param;
	if (button == 4)
		args->zoom *= zoom_rate;
	else if (button == 5)
		args->zoom /= zoom_rate;
	return (0);
}

int	loop_hook(void *param)
{
	t_hook_params	*args;

	args = param;
	if (!args->image)
		args->image = mlx_new_image(args->mlx, args->width, args->height);
	args->buffer = (int *)mlx_get_data_addr(
			args->image, &args->pixel_bits, &args->line_pixels, &args->endian);
	args->fractal(args);
	mlx_put_image_to_window(args->mlx, args->win, args->image, 0, 0);
	return (0);
}
