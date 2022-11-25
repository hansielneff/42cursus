/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:24:49 by helneff           #+#    #+#             */
/*   Updated: 2022/11/24 13:50:12 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

typedef struct s_hook_params
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	void		*image;
	int			*buffer;
	int			pixel_bits;
	int			line_pixels;
	int			endian;
	void		(*fractal)(struct s_hook_params *args);
	int			max_iterations;
	long double	pos_x;
	long double	pos_y;
	long double	zoom;
	long double	z_real;
	long double	z_imag;
	long double	c_real;
	long double	c_imag;
	long double	prev_real;
	long double	prev_imag;
}	t_hook_params;

int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		loop_hook(void *param);

#endif
