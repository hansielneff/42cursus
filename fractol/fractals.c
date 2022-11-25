/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:06:33 by helneff           #+#    #+#             */
/*   Updated: 2022/11/24 14:50:53 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static int	iterate(t_hook_params *args, int max_iterations)
{
	int	iter;

	iter = 0;
	while (iter++ < max_iterations)
	{
		args->prev_real = args->z_real;
		args->prev_imag = args->z_imag;
		args->z_real = args->prev_real * args->prev_real
			- args->prev_imag * args->prev_imag + args->c_real;
		args->z_imag = 2 * args->prev_real * args->prev_imag + args->c_imag;
		if ((args->z_real * args->z_real + args->z_imag * args->z_imag) > 4)
			break ;
	}
	return (iter);
}

void	julia(t_hook_params *args)
{
	const int	max_iterations = args->max_iterations;
	int			color;
	int			iter;
	int			i;

	i = 0;
	while (i < args->width * args->height)
	{
		args->z_real = 1.5 * (i % args->width - args->width / 2)
			/ (0.5 * args->zoom * args->width) + args->pos_x;
		args->z_imag = (i / args->width - args->height / 2)
			/ (0.5 * args->zoom * args->height) + args->pos_y;
		iter = iterate(args, max_iterations);
		color = (int)(0x0000FF * ((long double)iter / max_iterations))
			<< (int)(16 * ((long double)iter / max_iterations));
		args->buffer
		[(i / args->width * args->line_pixels / 4) + i % args->width] = color;
		++i;
	}
}

void	mandelbrot(t_hook_params *args)
{
	const int	max_iterations = args->max_iterations;
	int			color;
	int			iter;
	int			i;

	i = 0;
	while (i < args->width * args->height)
	{
		args->c_real = 1.5 * (i % args->width - args->width / 2)
			/ (0.5 * args->zoom * args->width) + args->pos_x;
		args->c_imag = (i / args->width - args->height / 2)
			/ (0.5 * args->zoom * args->height) + args->pos_y;
		args->z_real = 0;
		args->z_imag = 0;
		iter = iterate(args, max_iterations);
		color = (int)(0x0000FF * ((long double)iter / max_iterations))
			<< (int)(16 * ((long double)iter / max_iterations));
		args->buffer
		[(i / args->width * args->line_pixels / 4) + i % args->width] = color;
		++i;
	}
}
