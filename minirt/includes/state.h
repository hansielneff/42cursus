/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:21:26 by helneff           #+#    #+#             */
/*   Updated: 2023/04/25 12:29:06 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

typedef struct s_window		t_window;
typedef struct s_scene_data	t_scene_data;
typedef struct s_camera		t_camera;

typedef struct s_state
{
	t_window		*window;
	t_scene_data	*scene;
	t_camera		*camera;
}	t_state;

#endif
