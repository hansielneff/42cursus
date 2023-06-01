/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:59 by helneff           #+#    #+#             */
/*   Updated: 2023/05/15 15:29:24 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>

# include "vec3.h"

typedef struct s_cylinder_data
{
	size_t					id;
	struct s_cylinder_data	*next;
	t_vec3					pos;
	t_vec3					dir;
	t_vec3					col;
	t_vec3					ray_pos;
	double					diameter;
	double					height;
}	t_cylinder_data;

typedef struct s_plane_data
{
	size_t				id;
	struct s_plane_data	*next;
	t_vec3				pos;
	t_vec3				dir;
	t_vec3				col;
}	t_plane_data;

typedef struct s_sphere_data
{
	size_t					id;
	struct s_sphere_data	*next;
	t_vec3					pos;
	t_vec3					col;
	double					diameter;
}	t_sphere_data;

typedef struct s_light_data
{
	t_vec3	pos;
	t_vec3	col;
	double	ratio;
}	t_light_data;

typedef struct s_ambient_light_data
{
	t_vec3	col;
	double	ratio;
}	t_ambient_light_data;

typedef struct s_camera_data
{
	t_vec3	pos;
	t_vec3	dir;
	double	fov;
}	t_camera_data;

typedef struct s_scene_data
{
	size_t					next_id;
	t_camera_data			camera;
	t_ambient_light_data	ambient;
	t_light_data			light;
	t_sphere_data			*spheres;
	t_plane_data			*planes;
	t_cylinder_data			*cylinders;
}	t_scene_data;

typedef int	(*t_parser)(t_scene_data *scene, const char *elem);

int				parse_scene_file(t_scene_data *scene, char *file_name);
void			free_scene(t_scene_data *scene);

int				eat_whitespace(const char **elem);
int				eat_comma(const char **elem);
int				parse_num(const char **elem, double *result);

int				parse_camera(t_scene_data *scene, const char *elem);
int				parse_ambient(t_scene_data *scene, const char *elem);
int				parse_light(t_scene_data *scene, const char *elem);
int				parse_sphere(t_scene_data *scene, const char *elem);
int				parse_plane(t_scene_data *scene, const char *elem);
int				parse_cylinder(t_scene_data *scene, const char *elem);

#endif
