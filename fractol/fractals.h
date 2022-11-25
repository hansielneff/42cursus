/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:06:54 by helneff           #+#    #+#             */
/*   Updated: 2022/11/24 14:48:45 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "hooks.h"

void	julia(t_hook_params *args);
void	mandelbrot(t_hook_params *args);

#endif
