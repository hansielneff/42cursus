/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:51:58 by helneff           #+#    #+#             */
/*   Updated: 2023/05/19 17:02:26 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <mlx.h>

#include "camera.h"
#include "parser.h"
#include "color.h"
#include "shape.h"
#include "light.h"

#include <stdio.h>
#include <math.h>

int	ray_trace(const t_state *state, t_ray ray)
{
	const t_shape	shape = nearest_intersect(state, ray);
	int				color;

	color = 0;
	if (shape.type != SHAPE_NONE)
		color = calculate_lighting(state, ray, &shape);
	return (color);
}

static void	iterate_pixels(
	const t_state *state, t_camera *cam, t_ray_trace_func rtf)
{
	t_ray	r;
	int		x;
	int		y;
	double	u;
	double	v;

	y = 0;
	while (y < state->window->height)
	{
		x = 0;
		while (x < state->window->width)
		{
			u = (double)x / (state->window->width - 1);
			v = (double)y / (state->window->height - 1);
			r = (t_ray){cam->orig, vec3_subtract(vec3_add(vec3_add(
							cam->ll_corner, vec3_scalar(cam->hori, u)),
						vec3_scalar(cam->vert, v)),
					cam->orig)};
			set_pixel(&cam->image, x, y, rtf(state, r));
			x++;
		}
		y++;
	}
}

void	init_camera(t_camera *camera, double aspect_ratio, const t_state *state)
{
	const double	theta = state->scene->camera.fov * M_PI / 180;
	t_vec3			right;

	camera->orig = state->scene->camera.pos;
	camera->dir = vec3_unit(state->scene->camera.dir);
	if (camera->dir.x == 0 && camera->dir.z == 0)
		camera->dir.x = 0.0001;
	camera->aspect_ratio = aspect_ratio;
	camera->height = 2 * tan(theta / 2);
	camera->width = camera->height * aspect_ratio;
	camera->focal_length = 1;
	right = vec3_unit(vec3_cross(camera->dir, (t_vec3){0, 1, 0}));
	camera->hori = vec3_negate(vec3_scalar(right, camera->width));
	camera->vert = vec3_scalar(
			vec3_cross(camera->hori, camera->dir), camera->height);
	camera->ll_corner = vec3_subtract(
			vec3_subtract(
				vec3_subtract(
					camera->orig,
					vec3_scalar(camera->hori, 0.5)),
				vec3_scalar(camera->vert, 0.5)),
			vec3_scalar(camera->dir, camera->focal_length));
}

t_image	*render(t_camera *camera, const t_state *state)
{
	const int		background = int2col(state, 0x00ABCDEF);

	if (init_image(&camera->image, state->window) == -1)
		return (NULL);
	fill_color(&camera->image, background);
	iterate_pixels(state, camera, ray_trace);
	return (&camera->image);
}
