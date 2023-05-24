/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 08:55:20 by jonascim          #+#    #+#             */
/*   Updated: 2023/05/19 17:16:19 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include <math.h>

t_vec3	calculate_specular(
	const t_state *state, t_ray ray, const t_shape *shape, t_vec3 light_dir)
{
	const t_vec3	reflection_dir = vec3_reflect(light_dir, shape->hit.normal);
	const t_vec3	specular_color = (t_vec3){0.5, 0.5, 0.5};
	const int		specular_shininess = 50;
	const float		specular_factor = pow(fmax(vec3_dot
				(vec3_unit(ray.dir), reflection_dir), 0), specular_shininess);
	const t_vec3	specular = vec3_scalar
		(vec3_scalar(specular_color, state->scene->light.ratio),
			specular_factor);

	return (specular);
}

t_vec3	calculate_diffuse(
	const t_state *state, const t_shape *shape, t_vec3 light_dir)
{
	t_vec3	diffuse;

	diffuse = vec3_scalar(
			vec3_scalar(shape->hit.ray_color, state->scene->light.ratio),
			vec3_dot(shape->hit.normal, light_dir));
	if (diffuse.x < 0 || diffuse.y < 0 || diffuse.z < 0)
		diffuse = (t_vec3){0, 0, 0};
	return (diffuse);
}

t_vec3	calculate_ambient(
	const t_state *state, const t_shape *shape)
{
	t_vec3			color;
	t_vec3			ambient;

	color.x = shape->hit.ray_color.x * (state->scene->ambient.col.x / 255.999);
	color.y = shape->hit.ray_color.y * (state->scene->ambient.col.y / 255.999);
	color.z = shape->hit.ray_color.z * (state->scene->ambient.col.z / 255.999);
	ambient = vec3_scalar(color, state->scene->ambient.ratio);
	return (ambient);
}

int	calculate_lighting(
	const t_state *state, t_ray ray, const t_shape *shape)
{
	const t_vec3	light_dir = vec3_unit(
			vec3_subtract(state->scene->light.pos, shape->hit.pos));
	const t_vec3	ambient = calculate_ambient(state, shape);
	const t_vec3	diffuse = calculate_diffuse(state, shape, light_dir);
	const t_vec3	specular = calculate_specular(state, ray, shape, light_dir);
	const t_vec3	result = vec3_scalar(vec3_add
			(ambient, vec3_add(diffuse, specular)), 1.0 / 3);

	if (shape->hit.is_shadowed)
		return (vec2col(state, vec3_scalar(ambient, 1.0 / 3), 0));
	return (vec2col(state, result, 0));
}
