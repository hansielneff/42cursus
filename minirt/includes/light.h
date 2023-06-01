/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 08:54:00 by jonascim          #+#    #+#             */
/*   Updated: 2023/05/05 12:32:53 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "state.h"
# include "ray.h"
# include "vec3.h"
# include "shape.h"
# include "color.h"

int		calculate_lighting(const t_state *state, t_ray ray,
			const t_shape *shape);
t_vec3	calculate_ambient(
			const t_state *state, const t_shape *shape);
t_vec3	calculate_diffuse(
			const t_state *state, const t_shape *shape, t_vec3 light_dir);
t_vec3	calculate_specular(
			const t_state *state, t_ray ray, const t_shape *shape,
			t_vec3 light_dir);
#endif
