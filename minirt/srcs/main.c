/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:58:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/05/16 16:59:33 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#include <libft.h>

#include "state.h"
#include "parser.h"
#include "window.h"
#include "camera.h"

#define IMG_WIDTH	1080
#define IMG_HEIGHT	720

static void	panic(int return_value, char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
	exit(return_value);
}

static int	expose_hook(void *param)
{
	static t_image	*image = NULL;
	t_state			*state;

	state = param;
	if (!image)
		image = render(state->camera, state);
	if (!image || !image->mlx_img)
		panic(1, "Failed to render image");
	mlx_put_image_to_window(
		state->window->mlx_ptr, state->window->win_ptr, image->mlx_img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	static t_window		window;
	static t_scene_data	scene;
	static t_camera		camera;
	static t_state		state = {&window, &scene, &camera};
	char				*extension;

	if (argc != 2)
		panic(1, "Usage: ./minirt scene_file");
	extension = argv[1] + ft_strlen(argv[1]) - 3;
	if (ft_strncmp(extension, ".rt", 3) != 0)
		panic(1, "File does not have correct extension (.rt)");
	if (parse_scene_file(&scene, argv[1]) == -1)
		panic(1, "Failed to parse scene file");
	if (init_mlx_window(&window, "MiniRT", IMG_WIDTH, IMG_HEIGHT) == -1)
		panic(1, "Failed to initialize MLX window");
	init_camera(&camera, (double)IMG_WIDTH / IMG_HEIGHT, &state);
	mlx_expose_hook(window.win_ptr, expose_hook, &state);
	mlx_loop(window.mlx_ptr);
	return (0);
}
