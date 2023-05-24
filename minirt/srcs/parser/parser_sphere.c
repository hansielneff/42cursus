/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/05/08 13:06:18 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

int	parse_sphere(t_scene_data *scene, const char *elem)
{
	t_sphere_data	*sphere;

	sphere = malloc(sizeof(t_sphere_data));
	if (!sphere)
		return (1);
	if (parse_num(&elem, &sphere->pos.x) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->pos.y) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->pos.z) || eat_whitespace(&elem)
		|| parse_num(&elem, &sphere->diameter) || eat_whitespace(&elem)
		|| parse_num(&elem, &sphere->col.x) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->col.y) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->col.z) || (*elem && *elem != '\n')
		|| sphere->col.x < 0 || sphere->col.x > 255
		|| sphere->col.y < 0 || sphere->col.y > 255
		|| sphere->col.z < 0 || sphere->col.z > 255)
		return (free(sphere), 1);
	sphere->next = scene->spheres;
	scene->spheres = sphere;
	sphere->id = scene->next_id++;
	return (0);
}
