/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:41:36 by helneff           #+#    #+#             */
/*   Updated: 2023/05/15 16:54:57 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int	point_in_shadow(const t_state *state, t_shape *shape)
{
	return (
		point_in_shadow_sphere(state, shape)
		|| point_in_shadow_cylinder(state, shape)
	);
}

t_shape	nearest_intersect(const t_state *state, t_ray ray)
{
	t_shape			shape;

	shape.type = SHAPE_NONE;
	shape.hit.t = -1;
	nearest_intersect_plane(state, ray, &shape);
	nearest_intersect_sphere(state, ray, &shape);
	nearest_intersect_cylinder(state, ray, &shape);
	if (shape.type != SHAPE_NONE)
		shape.hit.is_shadowed = point_in_shadow(state, &shape);
	return (shape);
}
