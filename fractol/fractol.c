/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:03:31 by helneff           #+#    #+#             */
/*   Updated: 2022/11/24 14:49:12 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <mlx.h>

#include "libft.h"
#include "fractals.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 360

static int	quit(void *param)
{
	(void)param;
	exit(0);
}

static void	parse_fractal_input(t_hook_params *params, char *argv[])
{
	const int	variation = ft_atoi(argv[3]);

	if (!ft_strncmp(argv[1], "jul", 3))
		params->fractal = julia;
	else if (!ft_strncmp(argv[1], "man", 3))
		params->fractal = mandelbrot;
	else
		params->fractal = NULL;
	params->max_iterations = ft_atoi(argv[2]);
	if (params->max_iterations == 0 || variation == 0)
		params->fractal = NULL;
	params->c_real = -0.7;
	params->c_imag = 0.27015;
	if (variation == 2)
	{
		params->c_real = -0.72;
		params->c_imag = 0.28;
	}
	else if (variation == 3)
	{
		params->c_real = -0.7;
		params->c_imag = 0.28;
	}
}

static void	register_hooks(t_hook_params *params, void *mlx, void *win)
{
	mlx_key_hook(win, key_hook, params);
	mlx_mouse_hook(win, mouse_hook, params);
	mlx_loop_hook(mlx, loop_hook, params);
	mlx_hook(win, 17, 0, quit, NULL);
}

static void	init_params(t_hook_params *params, void *mlx, void *win)
{
	ft_bzero(params, sizeof(*params));
	params->mlx = mlx;
	params->win = win;
	params->width = SCREEN_WIDTH;
	params->height = SCREEN_HEIGHT;
	params->zoom = 1;
	params->fractal = NULL;
}

int	main(int argc, char *argv[])
{
	void			*mlx;
	void			*win;
	t_hook_params	params;

	if (argc != 4)
	{
		ft_printf("usage: fractol (jul|man) (iterations) (variation)\n");
		return (1);
	}
	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Fractol");
	if (!win)
		return (1);
	init_params(&params, mlx, win);
	parse_fractal_input(&params, argv);
	if (!params.fractal)
	{
		ft_printf("usage: fractol (jul|man) (iterations) (variation)\n");
		mlx_destroy_window(params.mlx, params.win);
		quit(&params);
	}
	register_hooks(&params, mlx, win);
	mlx_loop(mlx);
}
