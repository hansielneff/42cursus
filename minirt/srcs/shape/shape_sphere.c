/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:33:45 by helneff           #+#    #+#             */
/*   Updated: 2023/05/08 13:25:43 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "shape.h"

t_intersect	sphere_intersect(t_vec3 center, double radius, t_ray ray)
{
	const t_vec3	oc = vec3_subtract(ray.orig, center);
	const double	a = vec3_length_squared(ray.dir);
	const double	half_b = vec3_dot(oc, ray.dir);
	const double	discriminant = half_b * half_b - a
		* (vec3_length_squared(oc) - radius * radius);
	t_intersect		intersect;

	intersect.t = -1;
	if (discriminant < 0)
		return (intersect);
	intersect.t = (-half_b - sqrt(discriminant)) / a;
	intersect.pos = ray_at(ray, intersect.t);
	intersect.normal = vec3_unit(vec3_subtract(intersect.pos, center));
	return (intersect);
}

void	nearest_intersect_sphere(
	const t_state *state, t_ray ray, t_shape *shape)
{
	t_shape_data	iter;
	t_intersect		intersect;

	iter.sphere = state->scene->spheres;
	while (iter.sphere)
	{
		intersect = sphere_intersect(iter.sphere->pos,
				iter.sphere->diameter / 2.0, ray);
		if (intersect.t > 0 && (shape->hit.t < 0 || intersect.t < shape->hit.t))
		{
			shape->type = SHAPE_SPHERE;
			shape->data.sphere = iter.sphere;
			shape->hit = intersect;
			shape->hit.ray_color = vec3_scalar(iter.sphere->col, 1 / 255.999);
		}
		iter.sphere = iter.sphere->next;
	}
}

int	point_in_shadow_sphere(const t_state *state, t_shape *shape)
{
	t_shape_data	iter;
	t_ray			ray;
	t_intersect		intersect;
	int				result;

	result = 0;
	iter.sphere = state->scene->spheres;
	while (iter.sphere)
	{
		if (iter.sphere->id == shape->data.sphere->id)
		{
			iter.sphere = iter.sphere->next;
			continue ;
		}
		ray.orig = shape->hit.pos;
		ray.dir = vec3_subtract(state->scene->light.pos, shape->hit.pos);
		intersect = sphere_intersect(
				iter.sphere->pos, iter.sphere->diameter / 2, ray);
		if (intersect.t > 0)
			result = 1;
		iter.sphere = iter.sphere->next;
	}
	return (result);
}
