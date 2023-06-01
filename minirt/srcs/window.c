/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:17:40 by helneff           #+#    #+#             */
/*   Updated: 2023/04/24 18:58:22 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <mlx.h>
#include <libft.h>

#include "window.h"

#define X_DESTROY	17

static int	exit_program(void *param)
{
	const t_window	*window = param;

	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit(0);
	return (0);
}

static int	key_hook(int keycode, void *param)
{
	if (keycode == 53)
		exit_program(param);
	return (0);
}

int	init_mlx_window(t_window *window, char *name, int width, int height)
{
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		return (-1);
	window->win_ptr = mlx_new_window(window->mlx_ptr, width, height, name);
	if (!window->win_ptr)
		return (-1);
	mlx_key_hook(window->win_ptr, key_hook, window);
	mlx_hook(window->win_ptr, X_DESTROY, 0L, exit_program, window);
	window->width = width;
	window->height = height;
	return (0);
}
