/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:38:56 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/25 16:14:30 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "state.h"
# include "vec3.h"

int	int2col(const t_state *state, int i);
int	vec2col(const t_state *state, t_vec3 v, double alpha);

#endif
