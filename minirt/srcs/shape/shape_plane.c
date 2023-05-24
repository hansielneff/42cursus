/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:26:46 by jonascim          #+#    #+#             */
/*   Updated: 2023/05/08 13:50:07 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "shape.h"

t_intersect	plane_intersect(t_ray ray, t_plane_data *plane)
{
	t_intersect	intersect;
	t_vec3		to_plane;
	double		denom;

	intersect.t = -1;
	denom = vec3_dot(ray.dir, plane->dir);
	if (fabs(denom) < 1e-6)
		return (intersect);
	to_plane = vec3_subtract(plane->pos, ray.orig);
	intersect.t = vec3_dot(to_plane, plane->dir) / denom;
	intersect.pos = ray_at(ray, intersect.t);
	intersect.normal = plane->dir;
	return (intersect);
}

void	nearest_intersect_plane(const t_state *state, t_ray ray, t_shape *shape)
{
	t_shape_data	iter;
	t_intersect		intersect;

	iter.plane = state->scene->planes;
	while (iter.plane)
	{
		intersect = plane_intersect(ray, iter.plane);
		if (intersect.t > 0 && (shape->hit.t < 0 || intersect.t < shape->hit.t))
		{
			shape->type = SHAPE_PLANE;
			shape->data.plane = iter.plane;
			shape->hit = intersect;
			shape->hit.ray_color = vec3_scalar(iter.plane->col, 1 / 255.999);
			shape->hit.t += 1e-6;
		}
		iter.plane = iter.plane->next;
	}
}

int	point_in_shadow_plane(const t_state *state, t_shape *shape)
{
	t_shape_data	iter;
	t_ray			ray;
	t_intersect		intersect;
	int				result;

	result = 0;
	iter.plane = state->scene->planes;
	while (iter.plane)
	{
		if (iter.plane->id == shape->data.plane->id)
		{
			iter.plane = iter.plane->next;
			continue ;
		}
		ray.orig = shape->hit.pos;
		ray.dir = vec3_subtract(state->scene->light.pos, shape->hit.pos);
		intersect = plane_intersect(ray, iter.plane);
		if (intersect.t > 0)
			result = 1;
		iter.plane = iter.plane->next;
	}
	return (result);
}
