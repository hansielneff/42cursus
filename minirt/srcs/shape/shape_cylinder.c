/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:13:40 by jonascim          #+#    #+#             */
/*   Updated: 2023/05/19 16:18:31 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "shape.h"

static double	calc_disc_and_roots(
	t_ray ray, t_cylinder_data *cylinder, double *t1, double *t2)
{
	const t_vec3	oc = vec3_subtract(ray.orig, cylinder->pos);
	const double	a = vec3_length_squared(vec3_cross(ray.dir, cylinder->dir));
	const double	b = 2 * vec3_dot(
			vec3_cross(ray.dir, cylinder->dir), vec3_cross(oc, cylinder->dir));
	const double	c = vec3_dot(
			vec3_cross(oc, cylinder->dir), vec3_cross(oc, cylinder->dir)
			) - pow((cylinder->diameter / 2), 2);
	const double	discriminant = pow(b, 2) - 4 * a * c;

	if (discriminant >= 0)
	{
		*t1 = (-b - sqrt(discriminant)) / (2 * a);
		*t2 = (-b + sqrt(discriminant)) / (2 * a);
	}
	return (discriminant);
}

static t_intersect	aux_cylinder_intersect(t_intersect intersect, t_ray ray,
	t_cylinder_data *cylinder, double t2)
{
	double			aux;
	const double	max = sqrt(pow(cylinder->height / 2, 2)
			+ pow(cylinder->diameter / 2, 2));

	intersect.pos = vec3_add(ray.orig, vec3_scalar(ray.dir, intersect.t));
	if (vec3_magnitude(vec3_subtract(intersect.pos, cylinder->pos)) > max)
	{
		intersect.t = t2;
		intersect.pos = vec3_add(ray.orig,
				vec3_scalar(ray.dir, intersect.t));
		if (vec3_magnitude(vec3_subtract(intersect.pos, cylinder->pos)) > max)
		{
			intersect.t = -1;
			return (intersect);
		}
	}
	if (vec3_magnitude(vec3_subtract(intersect.pos, cylinder->pos))
		<= cylinder->height)
	{
		aux = vec3_dot(cylinder->dir,
				vec3_subtract(intersect.pos, cylinder->pos));
		intersect.normal = vec3_unit(vec3_subtract(intersect.pos,
					vec3_add(cylinder->pos, vec3_scalar(cylinder->dir, aux))));
	}
	return (intersect);
}

t_intersect	cylinder_intersect(t_ray ray, t_cylinder_data *cylinder)
{
	t_intersect		intersect;
	double			t1;
	double			t2;
	const double	discriminant = calc_disc_and_roots(ray, cylinder, &t1, &t2);

	intersect.t = -1;
	if (discriminant >= 0)
	{
		if (t2 < 0)
			return (intersect);
		intersect.t = t2;
		if (t1 > 0)
			intersect.t = t1;
		intersect = aux_cylinder_intersect(intersect, ray, cylinder, t2);
	}
	return (intersect);
}

void	nearest_intersect_cylinder(
	const t_state *state, t_ray ray, t_shape *shape)
{
	t_shape_data	iter;
	t_intersect		intersect;

	iter.cylinder = state->scene->cylinders;
	while (iter.cylinder)
	{
		intersect = cylinder_intersect(ray, iter.cylinder);
		if (intersect.t > 0 && (shape->hit.t < 0 || intersect.t < shape->hit.t))
		{
			shape->type = SHAPE_CYLINDER;
			shape->data.cylinder = iter.cylinder;
			shape->hit = intersect;
			shape->hit.ray_color = vec3_scalar(iter.cylinder->col, 1 / 255.999);
		}
		iter.cylinder = iter.cylinder->next;
	}
}

int	point_in_shadow_cylinder(const t_state *state, t_shape *shape)
{
	t_shape_data	iter;
	t_ray			ray;
	t_intersect		intersect;
	int				result;

	result = 0;
	iter.cylinder = state->scene->cylinders;
	while (iter.cylinder)
	{
		if (iter.cylinder->id == shape->data.cylinder->id)
		{
			iter.cylinder = iter.cylinder->next;
			continue ;
		}
		ray.orig = shape->hit.pos;
		ray.dir = vec3_subtract(state->scene->light.pos, shape->hit.pos);
		intersect = cylinder_intersect(ray, iter.cylinder);
		if (intersect.t > 0)
			result = 1;
		iter.cylinder = iter.cylinder->next;
	}
	return (result);
}
