/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:38:56 by jonascim          #+#    #+#             */
/*   Updated: 2023/05/04 10:57:03 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

double	vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_scalar(t_vec3 v, double n);
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_subtract(t_vec3 v1, t_vec3 v2);

t_vec3	vec3_negate(t_vec3 v);
double	vec3_length_squared(t_vec3 v);
double	vec3_magnitude(t_vec3 v);
t_vec3	vec3_unit(t_vec3 v);
t_vec3	vec3_reflect(t_vec3 v, t_vec3 n);
#endif
