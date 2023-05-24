/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/24 13:59:21 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

int	parse_camera(t_scene_data *scene, const char *elem)
{
	static int	first = 1;

	if (!first)
		return (1);
	first = 0;
	if (parse_num(&elem, &scene->camera.pos.x) || eat_comma(&elem)
		|| parse_num(&elem, &scene->camera.pos.y) || eat_comma(&elem)
		|| parse_num(&elem, &scene->camera.pos.z) || eat_whitespace(&elem)
		|| parse_num(&elem, &scene->camera.dir.x) || eat_comma(&elem)
		|| parse_num(&elem, &scene->camera.dir.y) || eat_comma(&elem)
		|| parse_num(&elem, &scene->camera.dir.z) || eat_whitespace(&elem)
		|| parse_num(&elem, &scene->camera.fov) || (*elem && *elem != '\n')
		|| scene->camera.dir.x < -1 || scene->camera.dir.x > 1
		|| scene->camera.dir.y < -1 || scene->camera.dir.y > 1
		|| scene->camera.dir.z < -1 || scene->camera.dir.z > 1
		|| scene->camera.fov < 0 || scene->camera.fov > 180)
		return (1);
	return (0);
}
