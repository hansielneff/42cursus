/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:15:59 by helneff           #+#    #+#             */
/*   Updated: 2023/05/04 10:57:01 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vec3.h"

t_vec3	vec3_negate(t_vec3 v)
{
	v.x *= -1;
	v.y *= -1;
	v.z *= -1;
	return (v);
}

double	vec3_length_squared(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vec3_magnitude(t_vec3 v)
{
	return (sqrt(vec3_length_squared(v)));
}

t_vec3	vec3_unit(t_vec3 v)
{
	t_vec3	unit;
	double	magnitude;

	magnitude = vec3_magnitude(v);
	unit.x = v.x / magnitude;
	unit.y = v.y / magnitude;
	unit.z = v.z / magnitude;
	return (unit);
}

t_vec3	vec3_reflect(t_vec3 v, t_vec3 n)
{
	t_vec3	reflection;
	double	dot;

	dot = vec3_dot(v, n);
	reflection = vec3_subtract(v, vec3_scalar(n, 2 * dot));
	return (reflection);
}
