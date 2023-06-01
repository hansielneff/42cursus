/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:43:05 by helneff           #+#    #+#             */
/*   Updated: 2023/04/25 16:14:17 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "color.h"
#include "window.h"

int	int2col(const t_state *state, int i)
{
	return (mlx_get_color_value(state->window->mlx_ptr, i));
}

int	vec2col(const t_state *state, t_vec3 v, double alpha)
{
	int	i;

	i = 0;
	i += (int)(255.999 * alpha) << 24;
	i += (int)(255.999 * v.x) << 16;
	i += (int)(255.999 * v.y) << 8;
	i += (int)(255.999 * v.z);
	return (int2col(state, i));
}
